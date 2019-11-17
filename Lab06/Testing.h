#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <stdexcept>
#include "Test.h"
#include "NodeTest.h"
#include "QueueTest.h"

class Testing{
    NodeTest node;
    QueueTest queue;
public:
    Testing();
    bool run();
};
#endif
