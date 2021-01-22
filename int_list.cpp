#include "int_list.h"

namespace mtm {
    IntList::IntList()
    {
        head = nullptr;
    }

    IntList::IntList(const IntList &list) : head(nullptr)
    {
        ListNode *temp = list.head;
        while (temp != nullptr) {
            insertStudent(temp->student);
            temp = temp->next;
        }
    }

    IntList &IntList::operator=(IntList list)
    {
        ListNode *temp(head);
        head = list.head;
        list.head = temp;
        return *this;
    }

    IntList::~IntList()
    {
        while (!listIsEmpty()) {
            removeFirst();
        }
    }

    bool IntList::listIsEmpty()
    {
        return head == nullptr;
    }

    bool IntList::studentIdIsValid(int student)
    {
        if (student < STUDENT_ID_LIMIT_LOW || student > STUDENT_ID_LIMIT_HIGH) {
            return false;
        }
        return true;
    }

    bool IntList::studentExists(int student)
    {
        if (listIsEmpty()) {
            return false;
        }
        ListNode *temp = head;
        if (temp->student == student) {
            return true;
        }
        while (temp->next != nullptr) {
            if (temp->student == student) {
                return true;
            }
            temp = temp->next;
        }
        if (temp->student == student) {
            return true;
        }
        return false;
    }

    InsertResult IntList::insertStudent(int student)
    {
        if (!studentIdIsValid(student)) {
            return INVALID_INSERT;
        }
        if (studentExists(student)) {
            return REPEATED_INSERT;
        }
        ListNode *new_node = new ListNode;
        new_node->student = student;
        new_node->next = nullptr;
        if (listIsEmpty() || head->student > student) {
            new_node->next = head;
            head = new_node;
            return SUCCESSFUL_INSERT;
        } else {
            ListNode *current = head;
            while (current->next != nullptr && current->next->student < new_node->student) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
            return SUCCESSFUL_INSERT;
        }

    }

    void IntList::removeFirst()
    {
        if (listIsEmpty()) {
            return;
        }
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    void IntList::removeByValue(int student)
    {
        if (!studentExists(student)) {
            return;;
        }
        if (head->student == student) {
            removeFirst();
            return;
        }
        ListNode *temp = head;
        while (temp->next != nullptr) {
            if (temp->next->student == student) {
                ListNode *current = temp->next;
                temp->next = temp->next->next;
                delete current;
                return;
            }
            temp = temp->next;
        }
        delete temp;
    }

    std::ostream &operator<<(std::ostream &os, IntList &list)
    {
        ListNode *temp;
        os << std::endl;
        if (!list.listIsEmpty()) {
            for (temp = list.head; temp != nullptr; temp = temp->next) {
                os << temp->student << std::endl;
            }
        }
        return os;
    }

};