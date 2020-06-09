#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_MANAGER_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_MANAGER_H

#include <queue>
#include <mutex>
#include <thread>

#include "data_container.h"
#include "random_generator.h"


class Manager{

protected:
    RandomGenerator randomGeneratorObj;
    DataQueue dataQueueObj;
    std::mutex queueMutex;

protected:
    void sleepThread();
};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_MANAGER_H
