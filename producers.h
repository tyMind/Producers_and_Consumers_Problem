#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H

#include "data_container.h"
#include "random_generator.h"
#include <thread>

class Producers{
public:
    Producers(){}
    Producers(int number);

    DataQueue dataQueue;
    RandomGenerator randomGenerator;
    void enqueue(int number);
    void dequeue();

    ~Producers();
};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
