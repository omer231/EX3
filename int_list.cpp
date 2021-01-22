#include "int_list.h"

namespace mtm {
    IntList::IntList()
    {
        head = nullptr;
    }

    IntList::IntList(const IntList &list) : head(nullptr)
    {
        listNode *temp = list.head;
        while (temp != nullptr) {
            insertStudent(temp->student);
            temp = temp->next;
        }
    }

    IntList &IntList::operator=(IntList list)
    {
        //IntList temp = list;
        std::swap(list.head, head);
        return *this;
    }

    IntList::~IntList()
    {
        while (!listIsEmpty()) {
            listRemove();
        }
    }

    bool IntList::listIsEmpty()
    {
        return head == nullptr;
    }

    bool IntList::validStudentId(int student)
    {
        if (student < STUDENT_ID_LIMIT_LOW || student > STUDENT_ID_LIMIT_HIGH) {
            return false;
        }
        return true;
    }

    bool IntList::doesStudentExist(int student)
    {
        if (listIsEmpty()) {
            return false;
        }
        listNode *temp = head;
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

    intListReturns IntList::insertStudent(int student)
    {
        if (!validStudentId(student)) {
            return INVALID_INSERT;
        }
        if (doesStudentExist(student)) {
            return REPEATED_INSERT;
        }
        auto *newNode = new listNode;
        newNode->student = student;
        newNode->next = nullptr;
        if (listIsEmpty() || head->student > student) {
            newNode->next = head;
            head = newNode;
            return SUCCESSFUL_INSERT;
        } else {
            listNode *curr = head;
            while (curr->next != nullptr && curr->next->student < newNode->student) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            return SUCCESSFUL_INSERT;
        }

    }

    void IntList::listRemove()
    {
        if (listIsEmpty()) {
            return;
        }
        listNode *temp = head;
        head = head->next;
        delete temp;
    }

    void IntList::listRemoveByValue(int student)
    {
        if (!doesStudentExist(student)) {
            return;;
        }
        if (head->student == student) {
            listRemove();
            return;
        }
        listNode *temp = head;
        while (temp->next != nullptr) {
            if (temp->next->student == student) {
                listNode *curr = temp->next;
                temp->next = temp->next->next;
                delete curr;
                return;
            }
            temp = temp->next;
        }
        delete temp;
    }

    std::ostream &operator<<(std::ostream &os, IntList &list)
    {
        listNode *temp;
        os << std::endl;
        if (!list.listIsEmpty()) {
            for (temp = list.head; temp != nullptr; temp = temp->next) {
                os << temp->student << std::endl;
            }
        }
        return os;
    }

};