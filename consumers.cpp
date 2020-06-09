#include "consumers.h"

void Consumers::consumeElems(int from, int to) {

    while(dataQueueObj.getQueueSize()==0){
        std::lock_guard<std::mutex>lck(queueMutex);

    }
    consumerCV.notify_all();
    int queueFrontElement=dataQueueObj.getDeleteFromQueue();
    //file object file.write() , seperate function in Consumer class which will call within the function of writing to the file

}

void Consumers::runConsumer(int from, int to) {
    sleepThread();
    consumeElems(from, to);
}