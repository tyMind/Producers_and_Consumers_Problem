#include "producers.h"


void Producers::produceElems(int from, int to) {
    //TODO: perform some check in this step
    int randomNumber=randomGeneratorObj.getRandomNumber(from, to);

    std::unique_lock<std::mutex>lck(queueMutex);

    if(dataQueueObj.getQueueSize()>=dataQueueObj.queueMaxSize){
        producersCV.wait(lck, [this]{return !(dataQueueObj.getQueueSize()<=80);});
        dataQueueObj.pushIntoQueue(randomNumber);
        producersCV.notify_all();


//        while(dataQueueObj.getQueueSize()>80){/*wait/lock while the queue elements number is not <=80 */}
//        dataQueueObj.pushIntoQueue(randomNumber);
//        producersCV.notify_all();  //notify other producers so that they would be able to push elements into queue
    }

    else{
        //
        dataQueueObj.pushIntoQueue(randomNumber);
    }
}


void Producers::runProducer(int from, int to) {
    sleepThread();
    produceElems(from, to);
}
