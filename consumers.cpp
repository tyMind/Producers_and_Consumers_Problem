#include "consumers.h"

void Consumers::consumeElems(int from, int to) {

    while(dataQueueObj.getQueueSize()==0){
        std::lock_guard<std::mutex>lck(queueMutex);

    }
    consumerCV.notify_all();
    int queueFrontElement=dataQueueObj.getDeleteFromQueue();
    containerCacheObj.writeToFile(queueFrontElement, "queue.txt");

}

void Consumers::runConsumer(int from, int to) {
    sleepThread();
    consumeElems(from, to);
}