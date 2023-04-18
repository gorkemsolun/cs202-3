/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Food class for Wildlife Simulation
 * */

#include "Food.h"

Food::Food() {}

Food::Food(pair<double, double> coordinates, int ID, int quality) {
    this->coordinates = coordinates;
    this->ID = ID;
    this->quality = quality;
}

int Food::getQuality() {
    return this->quality;
}

int Food::getID() {
    return this->ID;
}

pair<double, double> Food::getCoordinates() {
    return this->coordinates;
}