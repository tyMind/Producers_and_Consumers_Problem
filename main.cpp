#include <iostream>
#include <vector>

#include "data_container.h"
#include "producers.h"
#include "random_generator.h"

void printNumOfElemsQueue(DataQueue& dataQueue){
    dataQueue.printNumQueueElements();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main() {

    int numberOfProducers, numberOfConsumers;
    DataQueue dataQueueObj;
    RandomGenerator randomGeneratorObj;
    Producers producerObj;

    std::cout<<"number of producers: ";
    std::cin>>numberOfProducers;
    std::cout<<"number of consumers: ";
    std::cin>>numberOfConsumers;

    std::vector<std::thread>producers(numberOfProducers);
    int from=0;
    int to=100;

    for(int i=0; i<numberOfProducers; i++){
        producers.push_back(std::thread(&Producers::runProducer, std::ref(producerObj), from, to));
    }

    for(auto &th: producers){
        th.join();
    }

    dataQueueObj.printNumQueueElements();

    std::thread timer(printNumOfElemsQueue, std::ref(dataQueueObj));
    timer.join();

}