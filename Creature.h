/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Creature class for Wildlife Simulation
 * */

#include <bits/stdc++.h>
using namespace std;

#ifndef INC_2023_CREATURE_H
#define INC_2023_CREATURE_H

class Creature {
public:
    Creature();
    Creature(pair<double, double> coordinates, int ID, int health);

    pair<double, double> getCoordinates();
    int getID();
    int getHealth();
    bool isAlive();
    void kill();
    //bool compareCreature(Creature &first, Creature &second);

private:
    pair<double, double> coordinates;
    int ID, health;
    bool alive;
};

#endif
