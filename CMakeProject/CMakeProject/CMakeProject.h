#pragma once

#include <iostream>
#ifndef CMakeProject_H
#define CMakeProject_H

struct point {
    double X = add(Y);
    double Y = add(X);

private:
    double add(double val)
    {
        double result;
         do {
            std::cout << "\nEnter coordinate = ";
            std::cin >> result;
            if (val == result) std::cout << "\nPlease, repeat value ";
        } while (val == result);
        return result;
    }

};

struct incision {
    point start;
    point end;
};
#endif 