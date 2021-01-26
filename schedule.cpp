#include "schedule.h"
#include <cstdlib>
#include <iostream>
#include <list>


namespace mtm {

    Schedule::Schedule()
    {
        event_lst = std::list<BaseEvent *>{};
    }

    Schedule::~Schedule()
    {
        for (std::list<BaseEvent *>::iterator schedule_it = event_lst.begin(); schedule_it != event_lst.end();
             ++schedule_it) {
            if ((*schedule_it) != nullptr) {
                delete (*schedule_it);
            }
        }
    }

    void Schedule::addEvents(const EventContainer &event_container)
    {
        for (EventContainer::EventIterator container_it = event_container.begin();
             container_it == event_container.end(); ++container_it) {
            for (std::list<BaseEvent *>::iterator schedule_it = event_lst.begin(); schedule_it != event_lst.end();
                 ++schedule_it) {
                mtm::BaseEvent &event = *container_it;
                if (event.getEventDate() == (*schedule_it)->getEventDate() &&
                    event.getEventName() == (*schedule_it)->getEventName()) {
                    throw EventAlreadyExists();
                }
            }
        }

        for (EventContainer::EventIterator container_it = event_container.begin();
             container_it != event_container.end(); ++container_it) {
            mtm::BaseEvent &event = *container_it;
            event_lst.push_back(event.clone());
        }
    }

    void Schedule::registerToEvent(DateWrap date, std::string name, int student)
    {
        bool event_found = false;
        for (std::list<BaseEvent *>::iterator schedule_it = event_lst.begin(); schedule_it != event_lst.end();
             ++schedule_it) {
            if ((*schedule_it)->getEventDate() == date && (*schedule_it)->getEventName() == name) {
                (*schedule_it)->registerParticipant(student);
                event_found = true;
            }
        }
        if (!event_found) {
            throw EventDoesNotExist();
        }
    }

    void Schedule::unregisterFromEvent(DateWrap date, std::string name, int student)
    {
        bool event_found = false;
        for (std::list<BaseEvent *>::iterator schedule_it = event_lst.begin(); schedule_it != event_lst.end();
             ++schedule_it) {
            if ((*schedule_it)->getEventDate() == date && (*schedule_it)->getEventName() == name) {
                (*schedule_it)->unregisterParticipant(student);
                event_found = true;
            }
        }
        if (!event_found) {
            throw EventDoesNotExist();
        }
    }

    struct EventFilter : BaseEvent {
        bool operator()(const mtm::BaseEvent *event1, const mtm::BaseEvent *event2);
    };

    bool compare(const mtm::BaseEvent *event1, const mtm::BaseEvent *event2)
    {
        if (event1->getEventDate() == event2->getEventDate()) {
            return event1->getEventName() > event2->getEventName();
        }
        return event1->getEventDate() > event2->getEventDate();
    }

    void Schedule::printAllEvents() const
    {
        std::list<BaseEvent *> event_filter_lst = event_lst;
        event_filter_lst.sort([](const mtm::BaseEvent *event1, const mtm::BaseEvent *event2) {
            return compare(event2, event1);
        });
        for (std::list<BaseEvent *>::const_iterator schedule_it = event_filter_lst.begin();
             schedule_it != event_filter_lst.end(); ++schedule_it) {
            (*schedule_it)->printShort(std::cout);
            cout << endl;
        }
    }

    void Schedule::printMonthEvents(int month, int year) const
    {
        std::list<BaseEvent *> event_filter_lst = event_lst;
        event_filter_lst.sort([](const mtm::BaseEvent *event1, const mtm::BaseEvent *event2) {
            return compare(event2, event1);
        });
        for (std::list<BaseEvent *>::const_iterator schedule_it = event_filter_lst.begin();
             schedule_it != event_filter_lst.end(); ++schedule_it) {
            if ((*schedule_it)->getEventDate().month() == month && (*schedule_it)->getEventDate().year() == year) {
                (*schedule_it)->printShort(std::cout);
                cout << endl;
            }
        }
    }

    void Schedule::printEventDetails(DateWrap date, std::string name) const
    {
        bool event_found = false;
        for (std::list<BaseEvent *>::const_iterator schedule_it = event_lst.begin(); schedule_it != event_lst.end();
             ++schedule_it) {
            if ((*schedule_it)->getEventDate() == date && (*schedule_it)->getEventName() == name) {
                (*schedule_it)->printLong(std::cout);
                cout << endl;
                event_found = true;
            }
        }
        if (!event_found) {
            throw EventDoesNotExist();
        }
    }


}