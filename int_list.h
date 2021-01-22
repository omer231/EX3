#ifndef EX302_INT_LIST_H
#define EX302_INT_LIST_H

#include <ostream>

const int STUDENT_ID_LIMIT_LOW = 1;
const int STUDENT_ID_LIMIT_HIGH = 1234567890;

namespace mtm {
    struct listNode {
        int student;
        listNode *next;
    };

    enum intListReturns {
        SUCCESSFUL_INSERT,
        REPEATED_INSERT,
        INVALID_INSERT
    };

    class IntList {
    private:
        listNode *head;
    public:
        IntList();

        IntList(const IntList &list);

        IntList &operator=(IntList list);

        ~IntList();

        bool listIsEmpty();

        static bool validStudentId(int student);

        bool doesStudentExist(int student);

        intListReturns insertStudent(int student);

        void listRemove();

        void listRemoveByValue(int student);

        friend std::ostream &operator<<(std::ostream &os, IntList &list);
    };

    std::ostream &operator<<(std::ostream &os, IntList &list);
}
#endif //EX302_INT_LIST_H
