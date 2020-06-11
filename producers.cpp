#include "producers.h"


void Producers::produceElems(int from, int to) {
    //TODO: perform some check in this step
//    int randomNumber=randomGeneratorObj.getRandomNumber(from, to);
//
//    std::unique_lock<std::mutex>lck(queueMutex);
//
//    if(dataQueueObj.getQueueSize()>=dataQueueObj.queueMaxSize){
//        producerCV.wait(lck);
//        while(dataQueueObj.getQueueSize()>80){/* wait/lock while the queue elements number is not <=80 */}
//        dataQueueObj.pushIntoQueue(randomNumber);
//        producerCV.notify_all();  //notify other producers so that they would be able to push elements into queue
//    }
//
//    else{
//            dataQueueObj.pushIntoQueue(randomNumber);
//    }

        //notify_all: unblock all waiting threads
        int randomNumber=randomGeneratorObj.getRandomNumber(from, to);

        std::unique_lock<std::mutex>lck(queueMutex);

        if(dataQueueObj.getQueueSize()>=dataQueueObj.queueMaxSize) {
            producerCV.wait(lck, [this] { return !(dataQueueObj.getQueueSize() <= 80); });
            dataQueueObj.pushIntoQueue(randomNumber);
            producerCV.notify_all();
            consumerCV.notify_all();
        }

        else{
            dataQueueObj.pushIntoQueue(randomNumber);
            producerCV.notify_all();
            consumerCV.notify_all();
        }

}


void Producers::runProducer(int from, int to) {
    sleepThread();
    produceElems(from, to);
}
