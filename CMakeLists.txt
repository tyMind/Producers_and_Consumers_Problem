cmake_minimum_required(VERSION 3.14)
project(Producers_and_Consumers_Problem)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Producers_and_Consumers_Problem main.cpp random_generator.h random_generator.cpp data_container.h data_container.cpp producers.h producers.cpp manager.h manager.cpp consumers.h consumers.cpp container_cache.h container_cache.cpp)