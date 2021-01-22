#include "festival.h"

namespace mtm {
    Festival::Festival(DateWrap date) : festivalDate(date)
    {}

    /**
    Festival::~Festival()
    = default;
    */

    Festival::~Festival()
    {
        while (head != nullptr) {
            node* temp = head;
            head = head->next;
            delete &temp->event;
            delete temp;
            length--;
        }
    }

    void Festival::add(const BaseEvent &event)
    {
        if (!(festivalDate == event.getEventDate())) {
            throw DateMismatch();
        }
        BaseEvent *newEvent = event.clone();
        node *newNode = new node(*newEvent, nullptr);
        if (head == nullptr) {
            head = newNode;
            //tail = newNode;
            length += 1;
            return;
        }
        node *curr = head;
        node *currNext = head->next;
        while (currNext != nullptr) {
            //cout<<(curr->event.getEventName() > newNode->event.getEventName())<<endl;
            if (curr->event.getEventName() > newNode->event.getEventName()) {   //FIX- LOWER FIRST!!
                newNode->next = currNext;
                curr->next = newNode;
                length += 1;
                return;
            }
            curr = currNext;
            currNext = curr->next;
        }
        curr->next = newNode;
        length += 1;
        //tail = newNode;
    }
}