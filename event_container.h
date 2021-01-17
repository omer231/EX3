#ifndef EX3_EVENT_CONTAINER_H
#define EX3_EVENT_CONTAINER_H

#include "base_event.h"

namespace mtm {
    struct iteratorNode {
        BaseEvent *data;
        iteratorNode *next;
    };

    class EventContainer {
    protected:
        iteratorNode *first;
    public:
        class EventIterator {
        private:
            iteratorNode *eventNode;
        public:
            EventIterator(iteratorNode node);

            EventIterator(const EventIterator &iterator);

            EventIterator &operator=(EventIterator iterator);

            ~EventIterator();

            void operator++();

            BaseEvent *operator*();

            friend bool operator==(EventIterator iter1, EventIterator iter2);

            friend bool operator!=(EventIterator iter1, EventIterator iter2);
        };

        EventContainer();

        void add(BaseEvent *event);

        EventIterator begin();

        EventIterator end();
    };

}

#endif //EX3_EVENT_CONTAINER_H
