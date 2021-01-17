#include "event_container.h"

namespace mtm {

    EventContainer::EventIterator::EventIterator(iteratorNode node)
    {
        eventNode = &node;
    }

    EventContainer::EventIterator::EventIterator(const EventIterator &iterator)
    {
        iteratorNode *temp = iterator.eventNode;
        while (temp != nullptr) {
            eventNode->data = temp->data;
            temp = temp->next;
        }
    }

    EventContainer::EventIterator &EventContainer::EventIterator::operator=(EventIterator iterator)
    {
        std::swap(eventNode, iterator.eventNode);
        return *this;
    }

    EventContainer::EventIterator::~EventIterator()
    {
        iteratorNode *next = this->eventNode;
        iteratorNode *curr;
        while (next != nullptr) {
            curr = next;
            next = next->next;
            delete curr;
        }
    }

    void EventContainer::EventIterator::operator++()
    {
        if (eventNode != nullptr) {
            eventNode = eventNode->next;
        }
    }

    BaseEvent *EventContainer::EventIterator::operator*()
    {
        if (eventNode != nullptr) {
            return eventNode->data;
        }
        return nullptr;
    }

    bool operator==(EventContainer::EventIterator iter1, EventContainer::EventIterator iter2)
    {
        if (*iter1 == *iter2) {
            return true;
        }
        return false;
    }

    bool operator!=(EventContainer::EventIterator iter1, EventContainer::EventIterator iter2)
    {
        return !operator==(iter1, iter2);
    }


}