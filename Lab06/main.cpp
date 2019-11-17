/**
*	@file main.cpp
*	@author John Gibbons
*	@modified Kyle Kappes-Sum
*	@date 2019.11.11
*/

#include <iostream>
#include <stdexcept>
#include "Queue.h"
#include "Testing.h"

int main(int argc, char* argv[])
{
	Testing testing;
	if(testing.run()){
		Queue q;
	}else{
		cout<<"\nTests failed\n";
	}
	return(0);
}
