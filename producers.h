#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H

#include "data_container.h"
#include "random_generator.h"

class Producers{
public:
    DataQueue dataQueue;
    RandomGenerator randomGenerator;
    void enqueue(int number){
        int randomNumber=randomGenerator.getRandomNumber();
        dataQueue.putIntoQueue(number);
    }

    void dequeue(){
        dataQueue.getDeleteFromQueue();
    }


};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
