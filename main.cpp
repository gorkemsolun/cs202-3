/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Main to run Wildlife Simulation
 * */


#include "SimulationMgr.h"
#include "Creature.h"
using namespace std;

int main(int argc, char** argv ){

    string file = argv[1];

    SimulationMgr wildlifeSimulation = SimulationMgr();
    wildlifeSimulation.run(file);

    return 0;
}