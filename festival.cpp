#include "festival.h"

namespace mtm {
    Festival::Festival(DateWrap date) : festivalDate(date)
    {}

    Festival::~Festival()
    = default;

    void Festival::add(const BaseEvent &event)
    {
        if (!(festivalDate == event.getEventDate())) {
            throw DateMismatch();
        }
        BaseEvent *newEvent = event.clone();
        node *newNode = new node(*newEvent, nullptr);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        node *curr = head;
        node *currNext = head->next;
        while (currNext != nullptr) {
            if (curr->event.getEventName() > newNode->event.getEventName()) {
                newNode->next = currNext;
                curr->next = newNode;
                return;
            }
            curr = currNext;
            currNext = curr->next;
        }
        curr->next = newNode;
        tail = newNode;
    }
}