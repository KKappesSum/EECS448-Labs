#ifndef NODE_TEST_H
#define NODE_TEST_H

#include <iostream>
#include <stdexcept>
#include "Test.h"
#include "Node.h"

class NodeTest: protected Test{
private:
    Node<int>* m_node; /** Node to be tested*/

    /**
    * Runs all tests evaluating the entry of the Node.
    * @return bool: If all tests passed, true.
    */
    bool testEntry();

    /**
    * Runs all tests evaluating the node pointer of Node.
    * @return bool: If all tests passed, true.
    */
    bool testNext();

    /**
    * Helper function to test if the Entry initalizes correctly.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testInitEntry();

    /**
    * Helper function to test if the Entry can be changed correctly.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testSetEntry(int value);

    /**
    * Helper function to test if the Node pointer initalizes correctly.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testInitNext();

    /**
    * Helper function to test if the Node pointer can be changed correctly.
    * @return string: A pass, fail, unkno value to be printed.
    */
    string testSetNext(int value);


public:
    NodeTest();
    ~NodeTest();

    /**
    * Runs all tests of the Node.
    */
    void run();
};
#endif
