#include <iostream>
#include "random_generator.h"

int RandomGenerator::getRandomNumber(int from, int to) {
    int randomNumber=rand()%to+from;
    return randomNumber;
}

int RandomGenerator::getRandomSleepTime(int from, int to){
    int randomSleepTime=rand()%to+from;
    return randomSleepTime;
}

int RandomGenerator::getRandomProducerThread(int numberOfProducers){
    int randomProducerThread=rand()%numberOfProducers;
    return randomProducerThread;
}

int RandomGenerator::getRandomConsumerThread(int numberOfConsumers){
    int randomConsumerThread=rand()%numberOfConsumers;
    return randomConsumerThread;
}