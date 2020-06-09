#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H

#include <thread>
#include <mutex>
#include <condition_variable>

#include "data_container.h"
#include "random_generator.h"
#include "manager.h"

class Producers: public Manager{
public:
    void produceElems(int from, int to);
    void runProducer(int from, int to);

private:
    std::condition_variable producersCV;

};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_PRODUCERS_H
