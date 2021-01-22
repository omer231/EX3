#ifndef EX302_INT_LIST_H
#define EX302_INT_LIST_H

#include <ostream>

const int STUDENT_ID_LIMIT_LOW = 1;
const int STUDENT_ID_LIMIT_HIGH = 1234567890;

namespace mtm {
    /**
     * ListNode - struct for nodes inside IntList
     */
    struct ListNode {
        /**
         * student = student id
         * next - ListNode with next student
         */
        int student;
        ListNode *next;
    };

    /**
     * InsertResult - possible result for insert function
     */
    enum InsertResult {
        SUCCESSFUL_INSERT,
        REPEATED_INSERT,
        INVALID_INSERT
    };

    /**
     * IntList - linked list with integers for student ID that are also priority values
     */
    class IntList {
    private:
        /**
         * head - ListNode inside IntList with first node in list
         */
        ListNode *head;
    public:
        /**
         * IntList Constructor
         */
        IntList();

        /**
         * IntList Copy Constructor
         * @param list
         */
        IntList(const IntList &list);

        /**
         * IntList Assignment Operator
         * @param list
         * @return identical list
         */
        IntList &operator=(IntList list);

        /**
         * IntList Destructor
         */
        ~IntList();

        /**
         * listIsEmpty
         * @return true if the list is empty
         *         false if thr list isn't tmprty
         */
        bool listIsEmpty();

        /**
         * studentIdIsValid
         * @param student
         * @return true if the ID is within guidelines (>0, <1234567890)
         *         false if the ID is not
         */
        static bool studentIdIsValid(int student);

        /**
         * studentExists
         * @param student
         * @return true if there is such a student in list
         *         false if there isn't
         */
        bool studentExists(int student);

        /**
         * insertStudent
         * @param student student to attempt to insert inside list
         * @return SUCCESSFUL_INSERT if the student was inserted
         *         REPEATED_INSERT if there's already such student in list
         *         INVALID_INSERT if student ID isn't valid
         */
        InsertResult insertStudent(int student);

        /**
         * removeFirst
         * remove first node in list
         */
        void removeFirst();

        /**
         * removeByValue
         * @param student student to remove
         */
        void removeByValue(int student);

        /**
         * Operator<<
         * @param os
         * @param list
         * @return IntList, each student in new line
         */
        friend std::ostream &operator<<(std::ostream &os, IntList &list);
    };

    std::ostream &operator<<(std::ostream &os, IntList &list);
}
#endif //EX302_INT_LIST_H
