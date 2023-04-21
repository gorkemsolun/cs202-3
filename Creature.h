/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Creature class for Wildlife Simulation
 * */

#ifndef INC_2023_CREATURE_H
#define INC_2023_CREATURE_H
#include <bits/stdc++.h>
using namespace std;

class Creature {
public:
    Creature();
    Creature(pair<double, double> coordinates, int ID, int health);

    pair<double, double> getCoordinates();
    int getID();
    int getHealth();
    void setHealth(int newHealth);
    bool isAlive();
    void kill();
    //bool compareCreature(Creature &first, Creature &second);
    void move(pair<double, double> coordinates);

private:
    pair<double, double> coordinates;
    int ID, health;
    bool alive;
};

#endif
