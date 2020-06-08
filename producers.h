#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H

#include "data_container.h"
#include "random_generator.h"
#include <thread>
#include <mutex>
#include "manager.h"

class Producers: public Manager{
public:
//    Producers(){}
//    Producers(int number);

    void produceElems(int from, int to);

    void runProducer(int from, int to);

//    ~Producers();

};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
