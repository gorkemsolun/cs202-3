/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Manager class for Wildlife Simulation
 * */


#include "Creature.h"
#include "Food.h"
#include "Heap.h"
#include <bits/stdc++.h>
using namespace std;

#ifndef INC_2023_SIMULATIONMGR_H
#define INC_2023_SIMULATIONMGR_H

class SimulationMgr {
public:
    void run(string fileName);
private:
    double calculateEuclideanDistance(pair<double, double> f, pair<double, double> s);
    void printCreatures(vector<Creature> &creatures);
    string fileName;
};

#endif //INC_2023_SIMULATIONMGR_H
