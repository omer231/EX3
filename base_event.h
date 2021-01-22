#ifndef EX302_BASE_EVENT_H
#define EX302_BASE_EVENT_H

#include "../partA/date_wrap.h"
#include "int_list.h"

namespace mtm {
    class BaseEvent {
    protected:
        /**
         * event_date - DateWrap with the event's date
         * event_name - string with the event's name
         * event_participants - IntList with events participants
         */
        DateWrap event_date;
        string event_name;
        IntList event_participants;
    public:

        /**
         * BaseEvent Constructor
         * @param date event_date - date
         * @param name event_name - name
         *
         */
        BaseEvent(DateWrap date, string name) : event_date(date),
                                                event_name(name),
                                                event_participants()
        {}

        /**
         * BaseEvent Destructor
         */
        virtual ~BaseEvent() = default;

        /**
         * registerParticipant - pure virtual
         * @param student student to attempt to insert in event_participant
         */
        virtual void registerParticipant(int student) = 0;

        /**
         * unregisterParticipant
         * @param student student to attempt to unregister from event
         */
        virtual void unregisterParticipant(int student)
        {
            if (!mtm::IntList::studentIdIsValid(student)) {
                throw InvalidStudent();
            } else {
                bool result = event_participants.studentExists(student);
                if (!result) {
                    throw NotRegistered();
                } else {
                    event_participants.removeByValue(student);
                }
            }
        }

        /**
         * printShort
         * @param os
         * @return event_name event_date
         */
        std::ostream &printShort(std::ostream &os)
        {
            os << event_name << " " << event_date << endl;
            return os;
        }

        /**
         * printLong
         * @param os
         * @return event_name event_date
         *         event_participants
         */
        std::ostream &printLong(std::ostream &os)
        {
            os << event_name << " " << event_date << event_participants;
            return os;
        }

        /**
         * clone - pure virtual
         * @return new identical event
         */
        virtual BaseEvent *clone() const = 0;

        /**
         * getEventDate const
         * @return the event's date, DateWrap
         */
        DateWrap getEventDate() const
        {
            return event_date;
        }

        /**
         * getEventName const
         * @return the event's name, string
         */
        string getEventName() const
        {
            return event_name;
        }
    };
}

#endif //EX302_BASE_EVENT_H
