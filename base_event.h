#ifndef EX302_BASE_EVENT_H
#define EX302_BASE_EVENT_H

#include <utility>

#include "../partA/date_wrap.h"
#include "int_list.h"

namespace mtm {
    class BaseEvent {
    protected:
        DateWrap *eventDate;
        string eventName;
        IntList *eventParticipants;
    public:
        BaseEvent(DateWrap date, string name) : eventDate(new DateWrap(date.day(), date.month(), date.year())),
                                                eventName(std::move(name))
        {
            eventParticipants = new IntList;
        }

        /**
        BaseEvent(BaseEvent const &base_event) : eventDate(base_event.eventDate),
                                                 eventName(base_event.eventName),
                                                 eventParticipants(base_event.eventParticipants)
        {}
         */

        virtual ~BaseEvent() = default;

        virtual void registerParticipant(int student) = 0;

        virtual bool unregisterParticipant(int student)
        {
            bool result = eventParticipants->doesStudentExist(student);
            if (!result) {
                throw NotRegistered();
            } else {
                eventParticipants->listRemoveByValue(student);
            }
        }

        std::ostream &printShort(std::ostream &os)
        {
            os << eventName << " " << *eventDate << endl;
            return os;
        }

        std::ostream &printLong(std::ostream &os)
        {
            os << eventName << " " << *eventDate << *eventParticipants;
            return os;
        }

        virtual BaseEvent *clone() const = 0;

        DateWrap getEventDate() const
        {
            return *eventDate;
        }

        string getEventName() const
        {
            return eventName;
        }
    };
}

#endif //EX302_BASE_EVENT_H
