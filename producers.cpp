#include "producers.h"


void Producers::produceElems(int from, int to) {
    //TODO: perform some check in this step
    queue_mutex.lock();

    int randomNumber=randomGeneratorObj.getRandomNumber(from, to);
    dataQueueObj.pushIntoQueue(randomNumber);
    if(dataQueueObj.getQueueSize()>=dataQueueObj.queueMaxSize){
        while(dataQueueObj.getQueueSize()>80){
            //block/sleep thread until the elements number in queue is <=80
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    queue_mutex.unlock();
}

void Producers::runProducer(int from, int to) {
    produceElems(from, to);
    sleepThread();
}

//Producers::~Producers() {
//    //call DataQueue and RandomGenerator destructor
//}