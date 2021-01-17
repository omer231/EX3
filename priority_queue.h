#ifndef EX3_PRIORITY_QUEUE_H
#define EX3_PRIORITY_QUEUE_H

#include <ostream>

#define STUDENT_ID_LIMIT 1234567891

namespace mtm {
    /**
     * Struct for nodes inside priority queue
     * @tparam T type of data inside node
     */
    struct Node {
        int data;
        Node *next;
    };

    /**
     * Enum for possible return values from pqInsert function
     */
    enum pqReturn {
        SUCCESSFUL_INSERT,
        REPEATED_INSERT,
        INVALID_INSERT
    };

    /**
     * Class for priority queue structure
     * @tparam T type of data inside node
     * @tparam condition the condition for whether or not to insert new node, for example if data is an int whether
     *      it's within certain numbers, returns TRUE for good value to be inserted, FALSE for not
     */
    class PriorityQueue {
    private:
        Node *first;
        int length;
    public:

        /**
         * Constructor
         * @param cond
         */
        PriorityQueue();

        /**
         * Copy Constructor
         * @param pq
         */
        PriorityQueue(const PriorityQueue& pq);

        /**
         * Assignment Operator
         * @param pq
         * @return
         */
        PriorityQueue &operator=(PriorityQueue pq);

        /**
         * Destructor
         */
        ~PriorityQueue();

        /**
         * pqLength
         * @return int length of queue
         */
        int pqLength();

        /**
         * pqIsEmpty
         * @return true if queue is empty
         *      false if queue isn't empty
         */
        bool pqIsEmpty();

        /**
         * pqDoesValueExist
         * @param data value to look for in queue
         * @return true if such value exists in queue
         *      false if no such value exists in queue
         */
        bool pqDoesValueExist(int data);

        static bool validStudentID(int student);

        /**
         * pqInsert - attempts to insert new data in queue, lower data is first in queue, no duplicates allowed
         * @param data new data to insert inside queue
         * @return SUCCESSFUL_INSERT if the data was inserted
         *      REPEATED_INSERT if the data was already in queue
         *      INVALID_INSERT if the data didn't pass the condition provided for the queue
         */
        pqReturn pqInsert(int data);

        /**
         * pqRemove - removes first node in queue
         */
        void pqRemove();

        /**
         * pqRemoveByValue - if the value exists in queue, removes the value and connects the nodes back correctly
         * @param data value to remove from queue
         */
        void pqRemoveByValue(int data);

        /**
         * Input Operator - prints to stream the data in queue, separated by line
         * @tparam Y type
         * @tparam cond condition
         * @param os ostream to print to
         * @param pq queue to print
         * @return ostream with the queue data
         */
        friend std::ostream &operator<<(std::ostream &os, PriorityQueue pq);
    };

    std::ostream &operator<<(std::ostream &os, PriorityQueue pq);
}
#endif //EX3_PRIORITY_QUEUE_H
