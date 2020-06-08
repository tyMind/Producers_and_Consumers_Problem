#include <iostream>
#include "random_generator.h"

int RandomGenerator::getRandomNumber(int from, int to) {
    int randomNumber=rand()%to+from;
    return randomNumber;
}

int RandomGenerator::getRandomSleepTime(int from, int to){
    int randomSleepTime=rand()%to+from;
    return randomSleepTime;
}

