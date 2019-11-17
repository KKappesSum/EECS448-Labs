#include "QueueTest.h"

QueueTest::QueueTest(){
    m_fileName = "Queue";
}

QueueTest::~QueueTest(){
    if(m_queue != nullptr){
        delete m_queue;
        m_queue = nullptr;
    }
}

void QueueTest::run(){
    cout<< "Starting Queue Test ...\n";
    testFunc("Testing Empty", (func) testEmpty(), ": ");
    testFunc("Testing Enqueue", (func) testEnqueue(), ": ");
    testFunc("Testing Dequeue", (func) testDequeue(), ": ");
    testFunc("Testing Peek", (func) testPeek(), ": ");
    cout<< "Queue Test Complete\n";
}

void QueueTest::resetQueue(){
    if(m_queue != nullptr){
        delete m_queue;
        m_queue = nullptr;
    }
    m_queue = new Queue();
}

bool QueueTest::testEmpty(){
    int count = 0;
    int maxCount = 4;
    string superT = "Testing Empty";

    try{
        string temp = testInitEmpty();
        subTest(superT, "Testing if Inits as Empty", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testRemoveEmpty();
        subTest(superT, "Testing if Content is Added at Creation", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testAddEmpty();
        subTest(superT, "Testing if Empty after Adding a Node", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testAddRemoveEmpty();
        subTest(superT, "Testing if Empty after Adding and Removing a Node", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    if(count != maxCount){
        return false;
    }
    return true;
}

string QueueTest::testInitEmpty(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty() == true){
        returnable = pass;
    }else{
        returnable = unkno;
    }
    return returnable;
}

string QueueTest::testRemoveEmpty(){
    string returnable = "\0";
    resetQueue();
    try{
         m_queue->dequeue();
         returnable = fail;
    }catch(exception e){
        returnable = pass;
    }
    return returnable;
}

string QueueTest::testAddEmpty(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty() == true){
        m_queue->enqueue(5);
        if(m_queue->isEmpty() == false){
            returnable = pass;
        }else{
            returnable = unkno;
        }
    }else{
        returnable = fail;
    }
    return returnable;
}

string QueueTest::testAddRemoveEmpty(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty() == true){
        m_queue->enqueue(5);
        if(m_queue->isEmpty() == false){
            m_queue->dequeue();
            if(m_queue->isEmpty() == true){
                returnable = pass;
            }else{
                returnable = unkno;
            }
        }else{
            returnable = unkno;
        }
    }else{
        returnable = fail;
    }
    return returnable;
}

bool QueueTest::testEnqueue(){
    int count = 0;
    int maxCount = 2;
    string superT = "Testing Enqueue";

    try{
        string temp = testInitEnqueue();
        subTest(superT, "Testing Enqueue on Empty", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testAddEnqueue();
        subTest(superT, "Testing Enqueue on Existing Queue", temp, ": ");
        if(temp == pass){
            count++;
        }else{
            temp = testAddBackEnqueue();
            subTest(superT, "|Additional Test| Testing Enqueue Bad Read", temp, ": ");
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    if(count != maxCount){
        return false;
    }
    return true;
}

string QueueTest::testInitEnqueue(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty() == true){
        m_queue->enqueue(5);
        if(m_queue->peekFront() == 5){
            returnable = pass;
        }else{
            returnable = unkno;
        }
    }else{
        returnable = fail;
    }
    return returnable;
}

string QueueTest::testAddEnqueue(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty() == true){
        m_queue->enqueue(5);
        if(m_queue->peekFront() == 5){
            m_queue->enqueue(7);
            if(m_queue->peekFront() == 5){
                returnable = pass;
            }else{
                returnable = unkno;
            }
        }else{
            returnable = unkno;
        }
    }else{
        returnable = fail;
    }

    return returnable;
}

string QueueTest::testAddBackEnqueue(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty() == true){
        m_queue->enqueue(5);
        if(m_queue->peekFront() == 5){
            m_queue->enqueue(7);
            if(m_queue->peekFront() == 7){
                returnable = fail;
            }else{
                returnable = unkno;
            }
        }else{
            returnable = unkno;
        }
    }else{
        returnable = unkno;
    }
    return returnable;
}

bool QueueTest::testDequeue(){
    int count = 0;
    int maxCount = 3;
    string superT = "Testing Dequeue";

    try{
        string temp = testInitDequeue();
        subTest(superT, "Testing Dequeue on Empty Queue", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testAddDequeue();
        subTest(superT, "Testing Dequeue on Single Queue", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testAdd2Dequeue();
        subTest(superT, "Testing Dequeue on 2 Item Queue", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    if(count != maxCount){
        return false;
    }
    return true;
}

string QueueTest::testInitDequeue(){
    string returnable = "\0";
    resetQueue();

    try{
        int count = 0;
        for(int i = 0; i < 100; i++){
            m_queue->dequeue();
            count = i;
        }
        if(count == 99){
            returnable = unkno;
        }else{
            returnable = fail;
        }
    }catch(exception e){
        returnable = pass;
    }

    return returnable;
}

string QueueTest::testAddDequeue(){
    string returnable = "\0";
    resetQueue();

    if(m_queue->isEmpty()){
        m_queue->enqueue(5);
        if(!m_queue->isEmpty()){
            m_queue->dequeue();
            if(m_queue->isEmpty()){
                returnable = pass;
            }else{
                returnable = unkno;
            }
        }else{
            returnable = unkno;
        }
    }else{
        returnable = fail;
    }

    return returnable;
}

string QueueTest::testAdd2Dequeue(){
    string returnable = "\0";
    resetQueue();

    if(m_queue->isEmpty()){
        m_queue->enqueue(5);
        if(!m_queue->isEmpty()){
            m_queue->enqueue(7);
            if(!m_queue->isEmpty()){
                m_queue->dequeue();
                if(!m_queue->isEmpty() && m_queue->peekFront() == 7){
                    m_queue->dequeue();
                    if(m_queue->isEmpty()){
                        returnable = pass;
                    }else{
                        returnable = unkno;
                    }
                }else{
                    returnable = fail;
                }
            }else{
                returnable = unkno;
            }
        }else{
            returnable = unkno;
        }
    }else{
        returnable = unkno;
    }

    return returnable;
}


bool QueueTest::testPeek(){
    int count = 0;
    int maxCount = 3;
    string superT = "Testing Peek";

    try{
        string temp = testInitPeek();
        subTest(superT, "Testing Peek on Empty Queue", temp, ": ");
        if(temp == pass){
            count++;
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testAddPeek();
        subTest(superT, "Testing Peek on Single Queue", temp, ": ");
        if(temp == pass){
            temp = testHardPeek();
            subTest(superT, "|Additional Test| Testing Peek is Not Hard Value", temp, ": ");
            if(temp == pass){
                count++;
            }
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    try{
        string temp = testAdd3Peek();
        subTest(superT, "Testing Peek on 3 Item Queue", temp, ": ");
        if(temp != pass){
            temp = testAddBackPeek();
            subTest(superT, "|Additional Test| Evaluating Queue Order", temp, ": ");
            if(temp != pass){
                temp = testAddReversePeek();
                subTest(superT, "|Additional Test| Evaluating Peek Location", temp, ": ");
                if(temp == pass){
                    count++;
                }
            }
        }
    }catch(exception e){
        failTry(e);
        return false;
    }

    if(count != maxCount){
        return false;
    }
    return true;
}

string QueueTest::testInitPeek(){
    string returnable = "\0";
    resetQueue();
    try{
        if(m_queue->isEmpty()){
            int temp = m_queue->peekFront();
            returnable = fail;
        }else{
            returnable = unkno;
        }
    }catch(exception e){
        returnable = pass;
    }
    return returnable;
}

string QueueTest::testAddPeek(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty()){
        m_queue->enqueue(5);
        if(m_queue->peekFront() == 5){
            returnable = pass;
        }else{
            returnable = unkno ;
        }
    }else{
        returnable = fail;
    }
    return returnable;
}

string QueueTest::testHardPeek(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty()){
        m_queue->enqueue(7);
        if(m_queue->peekFront() == 7){
            returnable = pass;
        }else{
            returnable = fail;
        }
    }else{
        returnable = unkno;
    }
    return returnable;
}

string QueueTest::testAdd3Peek(){
    string returnable = "\0";
    resetQueue();
    if(m_queue->isEmpty()){
        m_queue->enqueue(5);
        m_queue->enqueue(7);
        m_queue->enqueue(10);
        if(!m_queue->isEmpty()){
            if(m_queue->peekFront() == 5){
                returnable = pass;
            }else if(m_queue->peekFront() == 10){
                returnable = fail;
            }else{
                returnable = unkno;
            }
        }else{
            returnable = unkno;
        }
    }else{
        returnable = unkno;
    }
    return returnable;
}

string QueueTest::testAddBackPeek(){
    string returnable = "\0";
    resetQueue();
    m_queue->enqueue(5);
    m_queue->enqueue(7);
    m_queue->enqueue(10);
    if(m_queue->peekFront() != 5){
        m_queue->dequeue();
        m_queue->dequeue();
        if(m_queue->peekFront() == 10){
            returnable = pass;
        }else{
            returnable = fail;
        }
    }else{
        returnable = unkno;
    }
    return returnable;
}

string QueueTest::testAddReversePeek(){
    string returnable = "\0";
    resetQueue();
    m_queue->enqueue(5);
    m_queue->enqueue(7);
    m_queue->enqueue(10);
    if(m_queue->peekFront() == 10){
        returnable = pass;
    }else{
        returnable = fail;
    }
    return returnable;
}
