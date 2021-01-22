#ifndef EX302_RECURRING_EVENT_H
#define EX302_RECURRING_EVENT_H

#include "event_container.h"

const int IS_NUM_POSITIVE = 1;

namespace mtm {
    template<class EventType>
    class RecurringEvent : public EventContainer {
        EventType *eventType;
    public:
        RecurringEvent(DateWrap first_date, string name, int num_occurrences, int interval_days)
        {
            if (num_occurrences < IS_NUM_POSITIVE) {
                throw InvalidNumber();
            }
            if (interval_days < IS_NUM_POSITIVE) {
                throw InvalidInterval();
            }
            node *temp = nullptr;
            for (int i = 0; i < num_occurrences; i++) {
                //DateWrap *nDate = new DateWrap(first_date + i * interval_days);
                EventType *nEvent = new EventType(first_date+i*interval_days, name);
                node *newNode = new node(*nEvent, nullptr);
                if (temp == nullptr) {
                    head = newNode;
                    //tail = newNode;
                    temp = newNode;
                    length += 1;
                } else {
                    temp->next = newNode;
                    temp = temp->next;
                    //tail = newNode;
                    length += 1;
                }
            }
        }

        ~RecurringEvent() override
        {
            while (head != nullptr) {
                node *temp = head;
                head = head->next;
                delete &temp->event;
                delete temp;
                length--;
            }
        }

        void add(BaseEvent const &event) override
        {
            throw NotSupported();
        }
    };
}

#endif //EX302_RECURRING_EVENT_H
