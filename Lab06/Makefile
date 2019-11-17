QueueDemo: main.o Queue.o Test.o Testing.o NodeTest.o QueueTest.o
	g++ -g -Wall -std=c++11 main.o Test.o Testing.o NodeTest.o QueueTest.o Queue.o -o QueueDemo

main.o: main.cpp Testing.h
	g++ -g -std=c++11 -c main.cpp

node.o: Node.h Node.hpp
	g++ -g -std=c++11 -c Node.hpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -c Test.cpp

Testing.o: Test.h Testing.h Testing.cpp
	g++ -g -std=c++11 -c Testing.cpp

NodeTest.o: Test.h NodeTest.h NodeTest.cpp
	g++ -g -std=c++11 -c NodeTest.cpp

QueueTest.o: Test.h QueueTest.h QueueTest.cpp
	g++ -g -std=c++11 -c QueueTest.cpp

clean:
	rm main.o Test.o Testing.o NodeTest.o QueueTest.o QueueDemo
