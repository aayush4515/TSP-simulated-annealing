#ifndef _CITY_
#define _CITY_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class City {

public:
    // default constructor
    City() = default;

    // constructor with input values
    City(string name, double xCoord, double yCoord) : cityName(name), x(xCoord), y(yCoord) { }

    // destructor
    ~City() = default;

    // setters
    void setCityName(std::string name) { cityName = name; }
    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    // getters
    const string& getCityName() const { return cityName; }
    const double getX() const { return x; }
    const double getY() const { return y; }

private:
    string cityName;
    double x;
    double y;
};

#endif
