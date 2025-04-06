#ifndef _RANDOM_
#define _RANDOM_

#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>

// generate a random double between 0 and 1
random_device rd;  // seed source
mt19937 g(rd()); // Mersenne Twister RNG
uniform_real_distribution<> dis(0.0, 1.0); // range [0.0, 1.0)

void randomNumber (int& i, int& j, int size) {
    //srand(time(0));
        i = rand() % size;
        j = rand() % size;;

        // check if i and j are same
        while (i == j) j = rand() % size;
}

#endif