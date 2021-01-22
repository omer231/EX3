#ifndef EX302_EVENT_CONTAINER_H
#define EX302_EVENT_CONTAINER_H

#include "base_event.h"

namespace mtm {
    class EventContainer {
    protected:
        /**
         * Node - struct for EventContainer
         */
        struct Node {
            /**
             * event - BaseEvent with event
             * next - Node with the next event
             */
            BaseEvent &event;
            Node *next;

            /**
             * Node Constructor
             * @param event BaseEvent
             * @param next next Node
             */
            Node(BaseEvent &event, Node *next) : event(event), next(next)
            {}

            /**
             * Node Copy Constructor
             * @param new_node
             */
            Node(Node const &new_node) : event(new_node.event), next(new_node.next)
            {}
        };

        /**
         * head - Node inside EventContainer, with first node in container, set to nullptr
         */
        Node *head = nullptr;

    public:
        /**
         * EventContainer Constructor
         */
        EventContainer()
        = default;;

        /**
         * EventContainer Destructor
         */
        virtual ~EventContainer()
        = default;

        /**
         * containerIsEmpty
         * @return true if the container is empty
         *         false if container isn't empty
         */
        bool containerIsEmpty()
        {
            return head == nullptr;
        }

        /**
         * add - pure virtual
         * @param event event to attempt to insert in container
         */
        virtual void add(const BaseEvent &event) = 0;

        /**
         * EventIterator - class for iterator inside container
         */
        class EventIterator {
        protected:
            /**
             * iterator - Node pointing to a node inside container
             */
            Node *iterator;
        public:
            /**
             * EventIterator Constructor
             * iterator set to nullptr
             */
            EventIterator() : iterator(nullptr)
            {}

            /**
             * EventIterator Copy Constructor
             * @param node
             */
            explicit EventIterator(Node *node) : iterator(node)
            {}

            /**
             * EventIterator
             * @param event_iterator
             * @return identical iterator
             */
            EventIterator &operator=(EventIterator event_iterator)
            {
                Node *temp(iterator);
                iterator = event_iterator.iterator;
                event_iterator.iterator = temp;
                return *this;
            }

            /**
             * Dereference Operator
             * @return BaseEvent in  the iterator node
             */
            virtual BaseEvent &operator*()
            {
                return iterator->event;
            }

            /**
             * ++Operator
             * @return iterator with next node
             */
            virtual EventIterator operator++()
            {
                iterator = iterator->next;
                return *this;
            }

            /**
             * == Operator
             * @param iter1
             * @param iter2
             * @return true if iter1, iter2 are pointing to same address
             *         false otherwise
             */
            friend bool operator==(EventIterator iter1, EventIterator iter2)
            {
                return iter1.iterator == iter2.iterator;
            }

            /**
             * != Operator
             * @param iter1
             * @param iter2
             * @return true if iter1, iter2 are not pointing to same address
             *         false otherwise
             */
            friend bool operator!=(EventIterator iter1, EventIterator iter2)
            {
                return iter1.iterator != iter2.iterator;
            }
        };

        /**
         * begin
         * @return EventIterator with first node in container (head)
         */
        virtual EventIterator begin()
        {
            return EventIterator(head);
        }

        /**
         * end
         * @return EventIterator with nullptr, to signify one node after last in container
         */
        virtual EventIterator end()
        {
            return EventIterator(nullptr);
        }
    };
}

#endif //EX302_EVENT_CONTAINER_H
