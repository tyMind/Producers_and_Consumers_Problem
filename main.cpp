#include <iostream>
#include <vector>
#include <cstring>

#include "data_container.h"
#include "random_generator.h"

#include "producers.h"
#include "consumers.h"

void printNumOfElemsQueue(DataQueue& dataQueue){
    dataQueue.printNumQueueElements();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main() {

    int numberOfProducers, numberOfConsumers;
    DataQueue dataQueueObj;
    RandomGenerator randomGeneratorObj;
    Producers producerObj;
    Consumers consumerObj;
    std::string queueFileName="data.txt";

    std::cout<<"number of producers: ";
    std::cin>>numberOfProducers;
    std::cout<<"number of consumers: ";
    std::cin>>numberOfConsumers;

    std::vector<std::thread>producers(numberOfProducers);
    std::vector<std::thread>consumers(numberOfConsumers);
    int from=0;
    int to=100;

    std::thread timer(printNumOfElemsQueue, std::ref(dataQueueObj));
    timer.join();

    for(int i=0; i<numberOfProducers; i++){
        producers.push_back(std::thread(&Producers::runProducer, std::ref(producerObj), from, to));
    }

    for(int i=0; i<numberOfConsumers; i++){
        consumers.push_back(std::thread(&Consumers::runConsumer, std::ref(consumerObj), from, to, queueFileName));
    }

    for(auto &th: producers){

        if(th.joinable()){
            th.join();
        }
    }

    for(auto &th: consumers){
        if(th.joinable()){
            th.join();
        }
    }

    std::string deleteQueueFile="";
    std::cout<<"if you want to delete the file that the queue elements were written to, then type yes, else no: ";
    std::cin>>deleteQueueFile;


    char* queueFileCharFormat=new char[queueFileName.length()+1];
    std::strcpy(queueFileCharFormat, queueFileName.c_str());
    if(deleteQueueFile=="yes"){
        if(std::remove(queueFileCharFormat)){
            std::cerr<<"remove operation failed"<<std::endl;
        }
        else{
            std::cout<<queueFileName<<" has been removed"<<std::endl;
        }
    }

    else{
        std::cout<<"as specified, the file has not been deleted"<<std::endl;
    }

}