#ifndef EX302_BASE_EVENT_H
#define EX302_BASE_EVENT_H

#include <utility>

#include "../partA/date_wrap.h"
#include "int_list.h"

namespace mtm {
    class BaseEvent {
    protected:
        /**
         * eventDate - DateWrap with the event's date
         * eventName - string with the event's name
         * eventParticipants - IntList with events participants
         */
        DateWrap eventDate;
        string eventName;
        IntList eventParticipants;
    public:

        /**
         * BaseEvent Constructor
         * @param date eventDate - date
         * @param name eventName - name
         *             eventParticipants - empty list
         */
        BaseEvent(DateWrap date, string name) : eventDate(date),
                                                eventName(std::move(name)),
                                                eventParticipants()
        {}

        /**
         * BaseEvent Destructor
         */
        virtual ~BaseEvent() = default;

        /**
         * registerParticipant - pure virtual
         * @param student student to attempt to insert in eventParticipant
         */
        virtual void registerParticipant(int student) = 0;

        virtual bool unregisterParticipant(int student)
        {
            if (!mtm::IntList::validStudentId(student)) {
                throw InvalidStudent();
            } else {
                bool result = eventParticipants.doesStudentExist(student);
                if (!result) {
                    throw NotRegistered();
                } else {
                    eventParticipants.listRemoveByValue(student);
                }
            }
        }

        std::ostream &printShort(std::ostream &os)
        {
            os << eventName << " " << eventDate << endl;
            return os;
        }

        std::ostream &printLong(std::ostream &os)
        {
            os << eventName << " " << eventDate << eventParticipants;
            return os;
        }

        virtual BaseEvent *clone() const = 0;

        DateWrap getEventDate() const
        {
            return eventDate;
        }

        string getEventName() const
        {
            return eventName;
        }
    };
}

#endif //EX302_BASE_EVENT_H
