#ifndef EX302_ONE_TIME_EVENT_H
#define EX302_ONE_TIME_EVENT_H

#include "event_container.h"

namespace mtm {
    template<class EventType>
    class OneTimeEvent : public EventContainer {
        EventType *eventType;
    public:
        OneTimeEvent(DateWrap date, string name)
        {
            EventType *nEvent = new EventType(date, name);
            node *newNode = new node(*nEvent, nullptr);
            head = newNode;
            //tail = newNode;
            length += 1;
        }

        ~OneTimeEvent() override
        {
            node *temp = head;
            delete &temp->event;
            delete temp;
            length--;
        }

        void add(BaseEvent const &event) override
        {
            throw NotSupported();
        }
    };
}

#endif //EX302_ONE_TIME_EVENT_H
