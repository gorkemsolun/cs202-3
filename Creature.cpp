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

int Creature::getID() const {
    return this->ID;
}

int Creature::getHealth() const {
    return this->health;
}

bool Creature::isAlive() const {
    return this->alive;
}

void Creature::kill() {
    this->alive = false;
}

void Creature::setHealth(int newHealth) {
    this->health = newHealth;
}

void Creature::move(pair<double, double> coordinates) {
    double h = this->health, ten = 10;
    double speed = (h <= ten) ? 1 : (double)(ten / h);
    double distance = sqrt(pow(this->coordinates.first - coordinates.first, 2)
                            + pow(this->coordinates.second - coordinates.second, 2));
    double yDif = abs(this->coordinates.second - coordinates.second);
    double xDif = abs(this->coordinates.first - coordinates.first);
    double dx = (speed * xDif) / distance;
    double dy = (speed * yDif) / distance;
    if (coordinates.first < this->coordinates.first) {
        dx *= -1;
    }
    if (coordinates.second < this->coordinates.second) {
        dy *= -1;
    }
    this->coordinates.first += dx;
    this->coordinates.second += dy;
}

