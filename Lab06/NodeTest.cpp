#include "NodeTest.h"

NodeTest::NodeTest(){
    m_node = new Node<int>(0);
    m_fileName = "Node";
}

void NodeTest::run(){
    cout<< "Starting Node Test ...\n";
    testFunc("Testing Entry", (func) testEntry(), ": ");
    testFunc("Testing Next", (func) testNext(), ": ");
    cout<< "Node Test Complete ...\n";
}

NodeTest::~NodeTest(){
    if(m_node != nullptr){
        delete m_node;
        m_node = nullptr;
    }
}

bool NodeTest::testEntry(){
    int count = 0;
    int maxCount = 2;
    string superT = "Testing Entry";

    //Testing Initial
    try{
        string temp = testInitEntry();
        subTest(superT, "Testing Inital Entry", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    //Testing Set
    try{
        string temp = testSetEntry(5);
        subTest(superT, "Testing Set Entry", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    //Determine Pass/Fail
    if(count != maxCount){
        return false;
    }
    return true;
}

bool NodeTest::testNext(){
    int count = 0;
    int maxCount = 2;
    string superT = "Testing Next";

    //Testing Invalid Node
    try{
        string temp = testInitNext();
        subTest(superT, "Testing Next Init", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    //Testing New Node
    try{
        string temp = testSetNext(7);
        subTest(superT, "Testing New Node", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    //Determine Pass/Fail
    if(count != maxCount){
        return false;
    }
    return true;
}

string NodeTest::testInitEntry(){
    if(m_node->getEntry() == 0){
        return pass;
    }else{
        return unkno;
    }
}

string NodeTest::testSetEntry(int value){
    m_node->setEntry(value);
    if(m_node->getEntry() != value){
        return unkno;
    }else{
        return pass;
    }
}

string NodeTest::testInitNext(){
    if(m_node->getNext() == nullptr){
        return pass;
    }else{
        return unkno;
    }
}

string NodeTest::testSetNext(int value){
    string returnable = "\0";
    Node<int>* tempNode = new Node<int>(value);
    m_node->setNext(tempNode);
    if(m_node->getNext() == tempNode){
        returnable = pass;
    }else{
        returnable = unkno;
    }
    delete tempNode;
    tempNode = nullptr;
    return returnable;
}
