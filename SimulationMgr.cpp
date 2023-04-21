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

/*
 * if id of first < second true, else false
 */


bool compareCreature(Creature &first, Creature &second) {
    if (first.getID() < second.getID()) {
        return true;
    }
    return false;
}

double calculateEuclidianDistance(pair<double, double> f, pair<double, double> s) {
    return sqrt(pow(f.first - s.first, 2) + pow(f.second - s.second, 2));
}

void printCreatures(vector<Creature> &creatures) {
    for (Creature creature : creatures) {
        cout << "Creature " << creature.getID() << ": ";
        cout << creature.getCoordinates().first << ", ";
        cout << creature.getCoordinates().second << endl;
    }
}


int main(int argc, char** argv) {
    string fileName = "C:\\Users\\pc\\Desktop\\2023\\data.txt";

    // Creating simulation space

    int livingCreatureCount = 0;
    vector<Creature> creatures;
    Heap foodQualityHeap = Heap("QUALITY");
    Heap foodTimeHeap = Heap("TIME");
    int time = 0;
    ifstream data(fileName);
    vector<string> foodInput;

    // Simulation start

    // Getting inputs

    string s;
    int n; getline(data, s); n = stoi(s);
    for (int i = 0; i < n; ++i) {
        getline(data, s);
        int k = 0, before = 0;
        int ID, health;
        pair<double, double> coordinates;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ',') {
                k++;
                if (k == 1) {
                    ID = stoi(s.substr(before, j - before));
                } else if (k == 2) {
                    coordinates.first = stod(s.substr(before, j - before));
                } else if (k == 3) {
                    coordinates.second = stod(s.substr(before, j - before));
                }
                before = j + 1;
            }
        }
        health = stoi(s.substr(before));
        creatures.emplace_back(coordinates, ID, health);
        livingCreatureCount++;
    }

    // sorting creatures according to their ids

    sort(creatures.begin(), creatures.end(), compareCreature);

    while (getline(data, s)) {
        int k = 0, before = 0;
        int ID, quality, spawnTime;
        pair<double, double> coordinates;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ',') {
                k++;
                if (k == 1) {
                    ID = stoi(s.substr(before, j - before));
                } else if (k == 2) {
                    coordinates.first = stod(s.substr(before, j - before));
                } else if (k == 3) {
                    coordinates.second = stod(s.substr(before, j - before));
                } else if (k == 4) {
                    quality = stoi(s.substr(before, j - before));
                }
                before = j + 1;
            }
        }
        spawnTime = stoi(s.substr(before));
        foodTimeHeap.heapInsert(Food(coordinates, ID, quality, spawnTime));
    }

    cout << fixed;
    cout << setprecision(2);

    // main simulation loop

    while (livingCreatureCount > 0) {

        // Showing all creatures

        printCreatures(creatures);

        // New foods

        while (!foodTimeHeap.heapIsEmpty() && foodTimeHeap.getTop().getTime() == time) {
            foodQualityHeap.heapInsert(foodTimeHeap.getTop());
            foodTimeHeap.heapDelete();
        }

        // Fighting period

        for (int i = 0; i < creatures.size(); ++i) {
            if (creatures[i].isAlive()) {
                for (int j = 0; j < creatures.size(); ++j) {
                    if (creatures[j].isAlive() && i != j && creatures[j].getHealth() <= creatures[i].getHealth() &&
                        calculateEuclidianDistance(creatures[i].getCoordinates(), creatures[j].getCoordinates()) < 2) {
                        creatures[j].kill();
                        livingCreatureCount--;
                    }
                }
            }
        }

        // Food consuming

        if (!foodQualityHeap.heapIsEmpty()) {
            for (Creature &creature : creatures) {
                if (creature.isAlive()) {
                    if (1 >= calculateEuclidianDistance(creature.getCoordinates(), foodQualityHeap.getTop().getCoordinates())) {
                        creature.setHealth(creature.getHealth() + foodQualityHeap.getTop().getQuality());
                        foodQualityHeap.heapDelete();
                    }
                }
            }
        }

        // Moving

        if (!foodQualityHeap.heapIsEmpty()) {
            for (Creature &creature : creatures) {
                if (creature.isAlive()) {
                    creature.move(foodQualityHeap.getTop().getCoordinates());
                }
            }
        }

        // Health update

        for (Creature &creature : creatures) {
            if (creature.isAlive()) {
                creature.setHealth(creature.getHealth() - 1);
                if (creature.getHealth() <= 0) {
                    creature.kill();
                    livingCreatureCount--;
                }
            }
        }

        // Time update

        ++time;
    }




    return 0;
}
