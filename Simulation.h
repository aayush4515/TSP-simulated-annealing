#ifndef _SIMULATION_
#define _SIMULATION_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "City.h"
#include "Tour.h"
#include "random.h"

using namespace std;

void simulateAnnealing(vector<City> destinationCities, double temperature, double coolingRate) {
    Tour initial(destinationCities);
    initial.generateInitialTour(destinationCities);
    int initialDistance = initial.getTotalDistance();
    cout << "\nInitial solution distance: " << initialDistance << endl;
    initial.printTour();

    // create a current solution; tour object
    Tour currentSolution(initial.getTour());

    Tour* best = new Tour(currentSolution.getTour());
    int numSolutionsTested = 0;
    int numSolutionsAccepted = 0;
    while (temperature > 1.0) {
        numSolutionsTested ++;
        Tour newSolution(currentSolution.getTour());
        int currDistance = 0;
        int newDistance = 0;

        // indices for swapping
        int i = 0;
        int j = 0;

        // randomize indices
        randomNumber (i, j, newSolution.tourSize());

        // swap two cities in newSolution
        swap(newSolution.getTour()[i], newSolution.getTour()[j]);
        // set the new distance after swapping
        newSolution.setNewDistance();

        // calculate currentSolution distance and newSolution distance
        currDistance = currentSolution.getTotalDistance();
        newDistance = newSolution.getTotalDistance();

        // generate a random number every iteration
        double random_double = dis(g);

        // calculate the acceptance probability
        double acceptanceProbability = exp((-1.0 * (newDistance - currDistance)) / temperature);

        // update the best to currentSolution if currDistance > bestDistance
        // if (newDistance - currDistance < 0) {
        //     currentSolution = newSolution;
        //     delete best;
        //     best = new Tour(currentSolution.getTour());
        //     numSolutionsAccepted ++;
        // }
        // // accept the new solution if the acceptance probability is greater than the above generated random double in (0,1)
        // else if (acceptanceProbability > random_double) {
        //     currentSolution = newSolution;
        //     delete best;
        //     best = new Tour(currentSolution.getTour());
        //     numSolutionsAccepted ++;
        // }

        if (acceptanceProbability > random_double) {
            currentSolution = newSolution;
            numSolutionsAccepted ++;
        }

        if (currentSolution.getTotalDistance() < best->getTotalDistance()) {
            delete best;
            best = new Tour(currentSolution.getTour());
        }
        temperature *= 1 - coolingRate;
    }

    cout << "\n\n\nNumber of new states tested: " << numSolutionsTested << endl;
    cout << "\nNumber of new states accepted: " << numSolutionsAccepted << endl;
    int finalDistance = best->getTotalDistance();
    cout << "\n\nFinal solution distance: " << finalDistance << endl;
    best->printTour();
    delete best;
}


#endif