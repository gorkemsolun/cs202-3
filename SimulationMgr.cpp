/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Manager class for Wildlife Simulation
 * */

#include "Food.h"
#include "Creature.h"
#include "Heap.h"

bool isFoodEligible(vector<string> &foodInput, int index, int time) {
    int k = 0;
    for (int i = 0; i < foodInput[index].size(); ++i) {
        if (foodInput[index][i] == ',') {
            k++;
        }
        if (k == 4) {
            k = i + 1;
            break;
        }
    }
    return time == stoi(foodInput[index].substr(k));
}

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


int main() {
    string f = "C:\\Users\\pc\\Desktop\\2023\\data.txt";

    // Creating simulation space

    int livingCreatureCount = 0;
    vector<Creature> creatures;
    Heap foodHeap;
    int time = 0;
    int currentIndexofFoodInputs = 0;
    ifstream data(f);

    // Simulation start

    // Getting inputs

    string s, d;
    int n; getline(data, s); n = stoi(s);
    vector<string> foodInput;
    for (int i = 0; i < n; ++i) {
        getline(data, s);
        int k = 0, before = 0;
        int ID, health;
        pair<double, double> coordinates;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ',') {
                k++;
                if (k == 1) {
                    d = s.substr(before, j - before);
                    ID = stoi(d);
                } else if (k == 2) {
                    d = s.substr(before, j - before);
                    coordinates.first = stod(d);
                } else if (k == 3) {
                    d = s.substr(before, j - before);
                    coordinates.second = stod(d);
                }
                before = j + 1;
            }
        }
        d = s.substr(before);
        health = stoi(d);

        creatures.emplace_back(coordinates, ID, health);
        livingCreatureCount++;
    }

    while (getline(data, s)) {
        foodInput.push_back(s);
    }

    // main simulation loop
    while (livingCreatureCount > 0) {

        // Showing all creatures

        cout << setprecision(2);
        for (Creature creature : creatures) {
            cout << "Creature " << creature.getID() << ": ";
            cout << creature.getCoordinates().first << ", ";
            cout << creature.getCoordinates().second << endl;
        }

        // New foods

        while (isFoodEligible(foodInput, currentIndexofFoodInputs, time)) {
            int k = 0, before = 0;
            int ID, quality;
            pair<double, double> coordinates;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == ',') {
                    k++;
                    if (k == 1) {
                        d = s.substr(before, j - before);
                        ID = stoi(d);
                    } else if (k == 2) {
                        d = s.substr(before, j - before);
                        coordinates.first = stod(d);
                    } else if (k == 3) {
                        d = s.substr(before, j - before);
                        coordinates.second = stod(d);
                    } else if (k == 4) {
                        d = s.substr(before, j - before);
                        quality = stoi(d);
                    }
                    before = j + 1;
                }
            }

            foodHeap.heapInsert(Food(coordinates, ID, quality));
            livingCreatureCount++;
            currentIndexofFoodInputs++;
        }

        // Fighting period

        sort(creatures.begin(), creatures.end(), compareCreature);

        for (int i = 0; i < creatures.size(); ++i) {
            if (creatures[i].isAlive()) {
                for (int j = 0; j < creatures.size(); ++j) {
                    if (2 > calculateEuclidianDistance(creatures[i].getCoordinates(), creatures[j].getCoordinates())
                        && creatures[j].getHealth() <= creatures[i].getHealth()) {
                        creatures[j].kill();
                    }
                }
            }
        }

        //


        ++time;
    }




    return 0;
}
