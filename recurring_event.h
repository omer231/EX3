#ifndef EX302_RECURRING_EVENT_H
#define EX302_RECURRING_EVENT_H

#include "event_container.h"

namespace mtm {
    template<class EventType>
    class RecurringEvent : public EventContainer {
        EventType eventType;
    public:
        RecurringEvent(DateWrap first_date, string name, int num_occurrences, int interval_days)
        {
            if (num_occurrences < 0) {
                throw InvalidNumber();
            }
            if (interval_days < 0) {
                throw InvalidInterval();
            }
            node *temp = nullptr;
            for (int i = 0; i < num_occurrences; i++) {
                EventType *nEvent = new EventType(first_date += i, name);
                //EventType *nEvent(first_date += i, name);
                //EventType nEvent = new EventType(first_date += i, name);
                node *newNode = new node(*nEvent, nullptr);
                if (temp == nullptr) {
                    head = newNode;
                    tail = newNode;
                    temp = newNode;
                } else {
                    temp->next = newNode;
                    tail = newNode;
                }
            }
        }

        ~RecurringEvent() override
        = default;

        void add(BaseEvent const &event) override
        {
            throw NotSupported();
        }
    };
}

#endif //EX302_RECURRING_EVENT_H
