#ifndef EX3_BASE_EVENT_H
#define EX3_BASE_EVENT_H

#include <iostream>
#include "priority_queue.h"
#include "date_wrap.h"


namespace mtm {
    class BaseEvent {
    protected:
        DateWrap *eventDate{};
        string eventName;
        PriorityQueue *studentList{};
    public:
        /**
         * Constructor
         * @param name BaseEvent name
         * @param date BaseEvent date
         */
        BaseEvent(string name, DateWrap *date);

        /**
         * Copy Constructor
         * @param base
         */
        BaseEvent(const BaseEvent& base);

        BaseEvent &operator=(const BaseEvent &event);

        ~BaseEvent();

        virtual void registerParticipant(int student) const = 0;

        virtual void unregisterParticipant(int student);

        virtual std::ostream &printShort(std::ostream &os);

        virtual std::ostream &printLong(std::ostream &os);

        virtual BaseEvent *clone() const = 0;

    };
}
#endif //EX3_BASE_EVENT_H
