#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_DATA_CONTAINER_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_DATA_CONTAINER_H

#include <iostream>
#include <queue>
#include <mutex>

class DataQueue{
protected:
    static std::queue<int>queue;
public:
    static const int queueMaxSize;
    static const int queueStandardSize;

public:
    void pushIntoQueue(int number);
    int getDeleteFromQueue();
    void printNumQueueElements();
    int getQueueSize();

};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_DATA_CONTAINER_H
