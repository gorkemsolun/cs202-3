/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Food class for Wildlife Simulation
 * */

#include <bits/stdc++.h>
using namespace std;

#ifndef INC_2023_FOOD_H
#define INC_2023_FOOD_H

class Food {
public:
    Food();
    Food(pair<double, double> coordinates, int ID, int quality);

    pair<double, double> getCoordinates();
    int getID();
    int getQuality();

private:
    pair<double, double> coordinates;
    int ID, quality;

};

#endif
