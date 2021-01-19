#ifndef EX302_EVENT_CONTAINER_H
#define EX302_EVENT_CONTAINER_H

#include <utility>

#include "base_event.h"

namespace mtm {
    class EventContainer {
    protected:
        struct node {
            BaseEvent &event;
            node *next;

            node(BaseEvent &event, node *next) : event(event), next(next)
            {}

            explicit node(node *newNode) : event(newNode->event), next(newNode->next)
            {}
        };

        node *head = nullptr;
        node *tail = nullptr;
        int length = 0;

    public:
        EventContainer()
        = default;;

        virtual ~EventContainer()
        = default;

        /**
        EventContainer &operator=(const EventContainer container)
        {
            node *temp = head;
            while (head) {
                temp = head;
                head = head->next;
                delete temp;
            }
            head = container.head;
        }
         */

        virtual void add(const BaseEvent &event) = 0;

        class EventIterator {
        protected:
            node *iterator;
        public:
            EventIterator() : iterator(nullptr)
            {}

            explicit EventIterator(node *node) : iterator(node)
            {}


            virtual BaseEvent &operator*()
            {
                return iterator->event;
            }

            virtual EventIterator operator++()
            {
                iterator = iterator->next;
                return *this;
            }

            friend bool operator==(EventIterator iter1, EventIterator iter2)
            {
                return &iter1 == &iter2;
            }

            friend bool operator!=(EventIterator iter1, EventIterator iter2)
            {
                return !operator==(std::move(iter1), std::move(iter2));
            }
        };

        virtual EventIterator begin()
        {
            return EventIterator(head);
        }

        virtual EventIterator end()
        {
            return EventIterator(head+length);
        }
    };

    /**
    bool operator==(EventContainer::EventIterator iter1, EventContainer::EventIterator iter2)
    {

    }

    bool operator!=(EventContainer::EventIterator iter1, EventContainer::EventIterator iter2)
    {

    }
     */

}

#endif //EX302_EVENT_CONTAINER_H
