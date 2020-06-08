#ifndef PRODUCERS_AND_CONSUMERS_PROBLEM_RANDOM_GENERATOR_H
#define PRODUCERS_AND_CONSUMERS_PROBLEM_RANDOM_GENERATOR_H

#include <iostream>

class RandomGenerator{
public:
    int getRandomSleepTime(int from, int to);
    int getRandomNumber(int from, int to);

};

#endif //PRODUCERS_AND_CONSUMERS_PROBLEM_RANDOM_GENERATOR_H
