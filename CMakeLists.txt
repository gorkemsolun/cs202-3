cmake_minimum_required(VERSION 3.24)
project(2023)

set(CMAKE_CXX_STANDARD 17)

add_executable(2023 main.cpp SimulationMgr.cpp Food.cpp Food.h Creature.cpp Creature.h Heap.cpp Heap.h SimulationMgr.h main.cpp)
