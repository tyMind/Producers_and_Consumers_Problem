#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_MANAGER_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_MANAGER_H

#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>

#include "data_container.h"
#include "random_generator.h"


class Manager{

protected:
    RandomGenerator randomGeneratorObj;
    DataQueue dataQueueObj;
    std::mutex queueMutex;

protected:
    void sleepThread();

protected:
    std::condition_variable consumerCV;
    std::condition_variable producerCV;
};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_MANAGER_H
