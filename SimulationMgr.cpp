/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Simulation Manager for Wildlife Simulation with main
 * */

#include "Heap.h"
#include "Food.h"
#include "Creature.h"
using namespace std;

double calculateEuclideanDistance(pair<double, double> f, pair<double, double> s) {
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
    //string fileName = argv[1];
    string fileName = "C:\\Users\\pc\\Desktop\\2023\\data.txt";

    // Creating simulation space

    int livingCreatureCount = 0, time = 0;
    vector<Creature> creatures;
    Heap foodQualityHeap = Heap("QUALITY");
    Heap foodTimeHeap = Heap("TIME");
    ifstream data(fileName);

    // Simulation start

    // Getting inputs

    string input;
    int n; getline(data, input); n = stoi(input);
    for (int i = 0; i < n; ++i) {
        getline(data, input);
        int k = 0, b = 0;
        int ID, health;
        pair<double, double> coordinates;
        for (int j = 0; j < input.size(); ++j) {
            if (input[j] == ',') {
                k++;
                if (k == 1) {
                    ID = stoi(input.substr(b, j - b));
                } else if (k == 2) {
                    coordinates.first = stod(input.substr(b, j - b));
                } else if (k == 3) {
                    coordinates.second = stod(input.substr(b, j - b));
                }
                b = j + 1;
            }
        }
        health = stoi(input.substr(b));
        creatures.emplace_back(coordinates, ID, health);
        livingCreatureCount++;
    }

    // sorting creatures according to their ids

    sort(creatures.begin(), creatures.end(), [](Creature first, Creature second)
                                                                {return first.getID() < second.getID();});

    while (getline(data, input)) {
        int k = 0, b = 0; // k is counter for ',' and before is index
        int ID, quality, spawnTime;
        pair<double, double> coordinates;
        for (int j = 0; j < input.size(); ++j) {
            if (input[j] == ',') {
                k++;
                if (k == 1) {
                    ID = stoi(input.substr(b, j - b));
                } else if (k == 2) {
                    coordinates.first = stod(input.substr(b, j - b));
                } else if (k == 3) {
                    coordinates.second = stod(input.substr(b, j - b));
                } else if (k == 4) {
                    quality = stoi(input.substr(b, j - b));
                }
                b = j + 1;
            }
        }
        spawnTime = stoi(input.substr(b));
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
                        calculateEuclideanDistance(creatures[i].getCoordinates(), creatures[j].getCoordinates()) < 2) {
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
                    if (1 >= calculateEuclideanDistance(creature.getCoordinates(), foodQualityHeap.getTop().getCoordinates())) {
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