#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H

#include <iostream>
#include <stdexcept>
#include "Test.h"
#include "Queue.h"

class QueueTest: protected Test{
private:
//Member Variables
    Queue* m_queue; /** Node to be tested*/

//Super Tests
    /**
    * Creates a fresh Queue.
    */
    void resetQueue();

    /**
    * Runs all tests evaluating the isEmpty() of the Queue.
    * @return bool: If all tests passed, true.
    */
    bool testEmpty();

    /**
    * Runs all tests evaluating the enqueue() of the Queue.
    * @return bool: If all tests passed, true.
    */
    bool testEnqueue();

    /**
    * Runs all tests evaluating the dequeue() of the Queue.
    * @return bool: If all tests passed, true.
    */
    bool testDequeue();

    /**
    * Runs all tests evaluating the peekFront() of the Queue.
    * @return bool: If all tests passed, true.
    */
    bool testPeek();

//isEmpty Tests
    /**
    * Helper function to test if the isEmpty() returns correctly.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testInitEmpty();

    /**
    * Helper function to test if the Queue is not prepopulated correctly.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testRemoveEmpty();

    /**
    * Helper function to test if the isEmpty() returns correctly when an item is
    * added.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddEmpty();

    /**
    * Helper function to test if the isEmpty() returns correctly after adding
    * and removing an item.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddRemoveEmpty();

//Enqueue tests
    /**
    * Helper function to test if enqueue() works with a single item.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testInitEnqueue();

    /**
    * Helper function to test if enqueue() works with a multiple items.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddEnqueue();

    /**
    * Helper function as an additional test if enqueue() to evaluate item
    * position if testAddEnqueue() does not return correctly.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddBackEnqueue();

//Dequeue Tests
    /**
    * Helper function to test if the queue is empty in addition to eariler tests.
    * Enacted on an empty queue.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testInitDequeue();

    /**
    * Helper function to test if dequeue() works with one item.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddDequeue();

    /**
    * Helper function to test if dequeue() works with multiple item.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAdd2Dequeue();

//Peek Tests
    /**
    * Helper function to test if peekFront() works on an empty queue.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testInitPeek();

    /**
    * Helper function to test if peekFront() works on a single item.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddPeek();

    /**
    * Helper function as an additional test checking if peekFront() works on
    * single items and is not hard coded.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testHardPeek();

    /**
    * Helper function to test if peekFront() works on mulitple items.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAdd3Peek();

    /**
    * Helper function as an additional test evaluating the order of items in the
    * queue to determine if a bug comes from peekFront() or enqueue().
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddBackPeek();

    /**
    * Helper function as an additional test evaluating the order of items in the
    * queue to determine if a bug comes from peekFront() or enqueue().
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testAddReversePeek();

public:
    QueueTest();
    ~QueueTest();

    /**
    * Runs all tests of the Node.
    */
    void run();
};

#endif
