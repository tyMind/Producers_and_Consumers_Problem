#include "container_cache.h"

void ContainerCache::writeToFile(int numberToWrite, std::string fileName) {
    std::ofstream ofstreamObj;

    ofstreamObj.open(fileName, std::ios::out | std::ios::app);
    if(!ofstreamObj.is_open()){
        std::cerr<<"file cannot be opened"<<std::endl;
    }

    ofstreamObj<<numberToWrite<<", ";

    ofstreamObj.close();

}