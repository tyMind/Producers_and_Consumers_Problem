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
    DataQueue dataQueue;
    RandomGenerator randomGenerator;

    std::cout<<"number of producers: ";
    std::cin>>numberOfProducers;
    std::cout<<"number of consumers: ";
    std::cin>>numberOfConsumers;

    std::vector<Producers>producers;
    for(int i=0; i<numberOfProducers; i++){
        int number=randomGenerator.getRandomNumber(0,100);
        Producers p(number);
        producers.push_back(p);
    }

    dataQueue.printNumQueueElements();

    std::thread timer(printNumOfElemsQueue, std::ref(dataQueue));
    timer.join();

}