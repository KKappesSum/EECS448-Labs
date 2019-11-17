#include "Testing.h"

Testing::Testing(){

}

bool Testing::run(){
    try{
        node.run();
        queue.run();
    }catch(exception e){
        cout<< "\n\nERROR: "<< e.what()<<"\n";
        return false;
    }
    return true;
}
