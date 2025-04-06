#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "City.h"
#include "Tour.h"
#include "Simulation.h"

using namespace std;

int main() {
    cout << "*** TSP using Simulated Annealing" << endl << endl;

    double startTemp = 0.0;
    double coolingRate = 0.0;

    cout << "Starting Temperature: ";
    cin >> startTemp;
    cout << "\n\nCooling Rate: ";
    cin >> coolingRate;

    // stores the destination cities
    vector<City> destinationCities;
    string fileName;

    // BEGIN: INTERFACE TO ENTER AND PRINT CITIES FROM .TXT FILE, STORES IN destinationCities

    // enter the filename
    cout << "\n\nPlease enter a file name (quit to end): ";
    cin >> fileName;

    if (fileName == "quit") return 0;

    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error: Could not open file '" << fileName << "'" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string word;
        vector<string> tokens;

        while (iss >> word) tokens.push_back(word);

        if (tokens.size() < 3) continue;

        double x = stod(tokens[tokens.size() - 2]);
        double y = stod(tokens[tokens.size() - 1]);

        // Join city name from beginning to the coordinate tokens
        string cityName = tokens[0];
        for (size_t i = 1; i < tokens.size() - 2; ++i) {
            cityName += " " + tokens[i];
        }

        destinationCities.emplace_back(cityName, x, y);
    }

    inFile.close();

    cout << "\nCities:" << endl;
    for (const City& c : destinationCities) {
        cout << '\t' << c.getCityName() << " (" << c.getX() << ", " << c.getY() << ")" << endl;
    }

    // END INTERFACE

    simulateAnnealing(destinationCities, startTemp, coolingRate);

    // // print destinationCities for testing
    // cout << "\n\n";
    // for (auto const& city : destinationCities){
    //     cout << city.getCityName() << " ";
    // }


    return 0;
}
