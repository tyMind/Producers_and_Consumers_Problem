#include <iostream>
#include "data_container.h"

//initialize dataQueue as it is a static member
std::queue<int> DataQueue::dataQueue;

void DataQueue::putIntoQueue(int number){
    dataQueue.push(number);
}

int DataQueue::getDeleteFromQueue() {
    int frontElement=dataQueue.front();
    dataQueue.pop();
    return frontElement;
}

void DataQueue::printNumQueueElements() {
    std::cout<<dataQueue.size();
}