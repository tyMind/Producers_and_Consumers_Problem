#include "producers.h"

Producers::Producers(int number){
    std::thread t{&Producers::enqueue, this, number};
    std::cout<<"thread id: "<<t.get_id()<<std::endl;
    t.detach();
    //thread t goes out of scope which will be bad
}

void Producers::enqueue(int number){
//    int randomNumber=randomGenerator.getRandomNum<<std::endlber();
    dataQueue.putIntoQueue(number);
}

void Producers::dequeue(){
    dataQueue.getDeleteFromQueue();
}

Producers::~Producers() {
    //call DataQueue and RandomGenerator destructor
}