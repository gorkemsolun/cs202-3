/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Food class for Wildlife Simulation
 * */

#include "Food.h"

Food::Food() {
    this->coordinates = make_pair(0,0);
    this->ID = -1;
    this->quality = -1;
}

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

Food &Food::operator=(const Food &right) {
    if (&right != this) {
        this->coordinates = right.coordinates;
        this->quality = right.quality;
        this->ID = right.ID;
    }
    return *this;
}
