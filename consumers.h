

#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_CONSUMERS_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_CONSUMERS_H


#include "data_container.h"
#include "random_generator.h"
#include <thread>
#include <mutex>
#include <condition_variable>

#include "manager.h"
#include "container_cache.h"

class Consumers: public Manager{

public:
    ContainerCache containerCacheObj;

public:
    void consumeElems(int from, int to);
    void runConsumer(int from, int to);

private:
    std::condition_variable consumerCV;
};


#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_CONSUMERS_H
