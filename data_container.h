#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_DATA_CONTAINER_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_DATA_CONTAINER_H

#include <iostream>
#include <queue>

class DataQueue{
private:
    static std::queue<int>dataQueue;
public:
    DataQueue(){}
    ~DataQueue(){}

    void putIntoQueue(int number);
    int getDeleteFromQueue();
    void printNumQueueElements();

};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_DATA_CONTAINER_H
