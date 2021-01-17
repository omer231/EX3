#include "priority_queue.h"

namespace mtm {

    PriorityQueue::PriorityQueue()
    {
        first = nullptr;
        length = 0;
    }

    PriorityQueue::PriorityQueue(const PriorityQueue &pq) : first(nullptr)
    {
        length = 0;
        Node *temp = pq.first;
        while (temp != nullptr) {
            pqInsert(temp->data);
            temp = temp->next;
        }
    }

    PriorityQueue &PriorityQueue::operator=(PriorityQueue pq)
    {
        std::swap(first, pq.first);
        return *this;
    }

    PriorityQueue::~PriorityQueue()
    {
        Node *next = this->first;
        Node *curr;
        while (next != nullptr) {
            curr = next;
            next = next->next;
            delete curr;
            length--;
        }
    }

    int PriorityQueue::pqLength()
    {
        return length;
    }

    bool PriorityQueue::pqIsEmpty()
    {
        return first == nullptr;
    }

    bool PriorityQueue::pqDoesValueExist(int data)
    {
        if (pqIsEmpty()) {
            return false;
        }
        Node *temp = first;
        if (temp->data == data) {
            return true;
        }
        while (temp->next != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        if (temp->data == data) {
            return true;
        }
        return false;
    }

    bool PriorityQueue::validStudentID (int student){
        if (student > 0 && student < STUDENT_ID_LIMIT) {
            return true;
        }
        return false;
    }

    pqReturn PriorityQueue::pqInsert(int data)
    {
        if (validStudentID(data) == false) { //!!!!!
            return INVALID_INSERT;
        }
        auto *temp = new Node;
        temp->data = data;
        temp->next = nullptr;
        if (pqIsEmpty()) {
            first = temp;
            length++;
            return SUCCESSFUL_INSERT;
        }
        if (pqDoesValueExist(data)) {
            delete temp;
            return REPEATED_INSERT;
        }
        if (temp->data > data) {
            temp->next = first;
            first = temp;
            length++;
            return SUCCESSFUL_INSERT;
        }
        Node *curr = first;
        Node *currNext = first->next;
        while (currNext != nullptr) {
            if (temp->data > data) {
                temp->next = currNext;
                curr->next = temp;
                length++;
                return SUCCESSFUL_INSERT;
            }
            curr = currNext;
            currNext = curr->next;
        }
        curr->next = temp;
        length++;
        return SUCCESSFUL_INSERT;
    }

    void PriorityQueue::pqRemove()
    {
        if (pqIsEmpty()) {
            return;
        }
        Node *temp = first;
        first = first->next;
        length--;
        delete temp;
    }

    void PriorityQueue::pqRemoveByValue(int data)
    {
        if (!pqDoesValueExist(data)) {
            return;
        }
        if (first->data == data) {
            Node *temp = first;
            first = first->next;
            delete temp;
            length--;
            return;
        }
        Node *temp = first;
        while (temp->next != nullptr) {
            if (temp->next->data == data) {
                Node *curr = temp->next;
                temp->next = temp->next->next;
                delete curr;
                length--;
                return;
            }
            temp = temp->next;
        }
        delete temp;
    }

    std::ostream &operator<<(std::ostream &os, PriorityQueue pq)
    {
        Node *temp;
        if (!pq.pqIsEmpty()) {
            for (temp = pq.first; temp != nullptr; temp = temp->next) {
                os << temp->data << std::endl;
            }
        }
        return os;
    }

}