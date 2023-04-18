/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Creature class for Wildlife Simulation
 * */

#include "Creature.h"


Creature::Creature() {
    this->alive = true;
}

Creature::Creature(pair<double, double> coordinates, int ID, int health) {
    this->coordinates = coordinates;
    this->ID = ID;
    this->health = health;
    this->alive = true;
}

pair<double, double> Creature::getCoordinates() {
    return this->coordinates;
}

int Creature::getID() {
    return this->ID;
}

int Creature::getHealth() {
    return this->health;
}

bool Creature::isAlive() {
    return this->alive;
}

void Creature::kill() {
    this->alive = false;
}

void Creature::setHealth(int newHealth) {
    this->health = newHealth;
}

