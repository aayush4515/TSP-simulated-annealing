#ifndef _TOUR_
#define _TOUR_

#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include "City.h"

using namespace std;

class Tour {

public:
    // default constructor
    Tour() : distance(0) { }

    // constructor: takes another tour as an argument, also calculate and set the tour distance
    // Tour (const Tour& t) : tour(t.tour), distance(0) {
    //     if (tour.empty()) return;
    //     City prevCity = tour[0];

    //     for (size_t i = 1; i < tour.size(); ++i) {
    //         distance += sqrt(pow(tour[i].getX() - prevCity.getX(), 2)
    //                        + pow(tour[i].getY() - prevCity.getY(), 2));
    //         prevCity = tour[i];
    //     }
    // }

    Tour (const vector<City> tour) : tour(tour), distance(0) {
        euclideanDistance(tour);
    }

    // copy assignment operator
    const Tour& operator=(const Tour& rhs) {
        if (this != &rhs) {
            this->tour = rhs.tour;
            this->distance = rhs.distance;
        }
        return *this;
    }

    void setCity(vector<City>& cities) { this->tour = cities; }
    void setNewDistance () {
        euclideanDistance(tour);
    }

    // getters
    vector<City>& getTour() { return this->tour; }
    size_t tourSize() const {return tour.size();}
    int getTotalDistance() const {return distance;}

    void printTour() {
        cout << "\nTour:" << endl << endl;

        for (size_t i = 0; i < tour.size(); ++i) {
            cout << tour[i].getCityName();
            if (i < tour.size() - 1) {
                cout << " -> ";
            }
        }
    }

    void generateInitialTour (vector<City>& destinationCities) {
    // random number generator
        mt19937 g(0);
        // shuffle the vector
        shuffle(destinationCities.begin(), destinationCities.end(), g);
        tour = destinationCities;
        euclideanDistance(destinationCities);

    }

private:
    vector<City> tour;
    int distance;
    void euclideanDistance (vector<City> cities) {
        distance = 0;
        if (tour.empty()) return;
        City prevCity = this->tour[0];

        for (size_t i = 1; i < tour.size(); ++i) {
            distance += sqrt(pow(tour[i].getX() - prevCity.getX(), 2)
                           + pow(tour[i].getY() - prevCity.getY(), 2));
            prevCity = tour[i];
        }
    }
};

#endif