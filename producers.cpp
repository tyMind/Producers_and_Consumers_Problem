#include "producers.h"


void Producers::produceElems(int from, int to) {
    //TODO: perform some check in this step
    int randomNumber=randomGeneratorObj.getRandomNumber(from, to);
    dataQueueObj.pushIntoQueue(randomNumber);
    if(dataQueueObj.getQueueSize()>=dataQueueObj.queueMaxSize){
        std::lock_guard<std::mutex>lck(queueMutex);
        while(dataQueueObj.getQueueSize()>80){}
        producersCV.notify_all();    
    }
}

void Producers::runProducer(int from, int to) {
    sleepThread();
    produceElems(from, to);
}
