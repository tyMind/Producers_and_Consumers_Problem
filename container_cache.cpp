#include "container_cache.h"

void ContainerCache::writeToFile(int numberToWrite, std::string fileName) {
    std::ofstream ofstreamObj;

    ofstreamObj.open(fileName, std::ios::out | std::ios::app);
    if(!ofstreamObj.is_open()){
        std::cerr<<"file cannot be opened for writing the data of queue into it"<<std::endl;
    }

    ofstreamObj<<numberToWrite<<", ";

    ofstreamObj.close();

}