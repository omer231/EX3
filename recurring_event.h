#ifndef EX302_RECURRING_EVENT_H
#define EX302_RECURRING_EVENT_H

#include "event_container.h"

const int IS_NUM_POSITIVE = 1;

namespace mtm {
    template<class EventType>
    class RecurringEvent : public EventContainer {
        /**
         * event_type
         */
        EventType *event_type;
    public:
        /**
         * RecurringEvent Constructor
         * @param first_date
         * @param name
         * @param num_occurrences
         * @param interval_days
         */
        RecurringEvent(DateWrap first_date, string name, int num_occurrences, int interval_days)
        {
            if (num_occurrences < IS_NUM_POSITIVE) {
                throw InvalidNumber();
            }
            if (interval_days < IS_NUM_POSITIVE) {
                throw InvalidInterval();
            }
            Node *temp = nullptr;
            for (int i = 0; i < num_occurrences; i++) {
                EventType *new_event = new EventType(first_date + i * interval_days, name);
                Node *new_node = new Node(*new_event, nullptr);
                if (temp == nullptr) {
                    head = new_node;
                    temp = new_node;
                } else {
                    temp->next = new_node;
                    temp = temp->next;
                }
            }
        }

        /**
         * RecurringEvent Destructor
         */
        ~RecurringEvent() override
        {
            while (!containerIsEmpty()) {
                Node *temp = head;
                head = head->next;
                delete &temp->event;
                delete temp;
            }
        }

        /**
         * add
         * @param event
         *      RecurringEvent doesn't support any event insertion
         */
        void add(BaseEvent const &event) override
        {
            throw NotSupported();
        }
    };
}

#endif //EX302_RECURRING_EVENT_H
