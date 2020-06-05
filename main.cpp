#include <iostream>
#include "data_container.h"
#include "producers.h"

int main() {

    DataQueue dataQueue;
    Producers producers;
    producers.enqueue(7);
    producers.enqueue(9);
    producers.enqueue(6);
    dataQueue.printNumQueueElements();
}