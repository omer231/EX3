#include "festival.h"

namespace mtm {
    Festival::Festival(DateWrap date) : festival_date(date)
    {}

    Festival::~Festival()
    {
        while (!containerIsEmpty()) {
            Node *temp = head;
            head = head->next;
            delete &temp->event;
            delete temp;
        }
    }

    void Festival::add(const BaseEvent &event)
    {
        if (festival_date != event.getEventDate()) {
            throw DateMismatch();
        }
        BaseEvent *new_event = event.clone();
        Node *new_node = new Node(*new_event, nullptr);
        if (containerIsEmpty() || head->event.getEventName() > new_node->event.getEventName()) {
            new_node->next = head;
            head = new_node;
            return;
        } else {
            Node *current = head;
            while (current->next != nullptr && current->next->event.getEventName() < new_node->event.getEventName()) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
    }
}