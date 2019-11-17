#include "Test.h"

Test::Test(){
    m_fileName = "NO TEST NAME";
}

void Test::testFunc(string write, func testFunction, string denom){
   cout << "["<< m_fileName<< "]"<< write;
   if(testFunction){
       cout << denom << pass;
   }else{
       cout << denom << fail;
   }
}

void Test::subTest(string super, string write, string testFunction, string denom){
    cout << "["<< m_fileName<< "]"<< "(" << super<< ") "<< write;
    cout<< denom << testFunction;
}

void Test::failTry(exception e){
    cout<<"\n ERROR: "<< e.what() << "\n";
}
