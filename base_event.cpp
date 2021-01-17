#include "base_event.h"
#include <iostream>

namespace mtm {

    BaseEvent::BaseEvent(string name, DateWrap *eventDate)
    {
        eventDate = new DateWrap(eventDate->day(), eventDate->month(), eventDate->year());
        eventName = name;
        studentList = new PriorityQueue();
    }

    BaseEvent::BaseEvent(const BaseEvent &base) : eventDate(new DateWrap(*base.eventDate)),
                                                  eventName(base.eventName),
                                                  studentList(
                                                          new PriorityQueue(*base.studentList))
    {

    }

    BaseEvent &BaseEvent::operator=(const BaseEvent &event)
    {
        if (this == &event) {
            return *this;
        }
        delete eventDate;
        auto *date = new DateWrap(event.eventDate->day(), event.eventDate->month(), event.eventDate->year());
        eventName = event.eventName;
        eventDate = date;
        return *this;
    }

    BaseEvent::~BaseEvent()
    {
        delete eventDate;
        delete studentList;
    }

    void BaseEvent::unregisterParticipant(int student)
    {
        bool result = studentList->pqDoesValueExist(student);
        if (!result) {
            throw mtm::Exceptions::NotRegistered();
        } else {
            studentList->pqRemoveByValue(student);
        }
    }

    std::ostream &BaseEvent::printShort(std::ostream &os)
    {
        os << eventName << eventDate;
        return os;
    }

    std::ostream &BaseEvent::printLong(std::ostream &os)
    {
        os << eventName << eventDate << studentList;
        return os;
    }
}