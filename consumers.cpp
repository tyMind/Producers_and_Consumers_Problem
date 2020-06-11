#include "consumers.h"

void Consumers::consumeElems(int from, int to, std::string queueFileName) {
//    while(dataQueueObj.getQueueSize()==0){
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //"block" consumers
//    }
//    consumerCV.notify_all();
//
//    std::unique_lock<std::mutex>lck(queueMutex);
//    int queueFrontElement=dataQueueObj.getDeleteFromQueue();
//    containerCacheObj.writeToFile(queueFrontElement, queueFileName);
//

    //notify_all: unblock all waiting threads
    std::unique_lock<std::mutex> lck(queueMutex);
    if (dataQueueObj.getQueueSize() == 0) {
        consumerCV.wait(lck, [this] { return !(dataQueueObj.getQueueSize() > 0); });
        int queueFrontElement=dataQueueObj.getDeleteFromQueue();
        containerCacheObj.writeToFile(queueFrontElement, queueFileName);
        producerCV.notify_all();
        consumerCV.notify_all();
    } else {

        dataQueueObj.getDeleteFromQueue();
        int queueFrontElement=dataQueueObj.getDeleteFromQueue();
        containerCacheObj.writeToFile(queueFrontElement, queueFileName);
        producerCV.notify_all();
        consumerCV.notify_all();
    }

}

void Consumers::runConsumer(int from, int to, std::string queueFileName) {
    sleepThread();
    consumeElems(from, to, queueFileName);
}