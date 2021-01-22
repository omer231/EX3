#ifndef EX302_ONE_TIME_EVENT_H
#define EX302_ONE_TIME_EVENT_H

#include "event_container.h"

namespace mtm {
    template<class EventType>
    class OneTimeEvent : public EventContainer {
        /**
         * event_type
         */
        EventType *event_type;
    public:
        /**
         * OneTimeEvent Constructor
         * @param date
         * @param name
         */
        OneTimeEvent(DateWrap date, string name)
        {
            EventType *new_event = new EventType(date, name);
            Node *new_node = new Node(*new_event, nullptr);
            head = new_node;
        }

        /**
         * OneTimeEvent Destructor
         */
        ~OneTimeEvent() override
        {
            Node *temp = head;
            delete &temp->event;
            delete temp;
        }

        /**
         * add
         * @param event
         *      OneTimeEvent doesn't support any event insertion
         */
        void add(BaseEvent const &event) override
        {
            throw NotSupported();
        }
    };
}

#endif //EX302_ONE_TIME_EVENT_H
