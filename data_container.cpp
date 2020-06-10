#include <iostream>
#include "data_container.h"

//initialize dataQueue as it is a static member
std::queue<int> DataQueue::queue;
const int DataQueue::queueMaxSize=100;
const int DataQueue::queueStandardSize=80;

void DataQueue::pushIntoQueue(int number){
    queue.push(number);
}

int DataQueue::getDeleteFromQueue() {
    int frontElement=queue.front();
    queue.pop();
    return frontElement;
}

void DataQueue::printNumQueueElements() {
    std::cout<<"queue size is: "<<queue.size()<<std::endl;
}

int DataQueue::getQueueSize(){
    return queue.size();
}