#include "producers.h"


void Producers::produceElems(int from, int to) {
        //notify_all: unblock all waiting threads
        int randomNumber=randomGeneratorObj.getRandomNumber(from, to);

        std::unique_lock<std::mutex>lck(queueMutex);

        if(dataQueueObj.getQueueSize()>=dataQueueObj.queueMaxSize) {
            producerCV.wait(lck, [this] { return !(dataQueueObj.getQueueSize() > 80); });
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
