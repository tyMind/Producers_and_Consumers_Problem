#include "manager.h"

void Manager::sleepThread() {
    int randomSleepTime=randomGeneratorObj.getRandomSleepTime(0, 100);
    std::this_thread::sleep_for(std::chrono::milliseconds(randomSleepTime));
}

