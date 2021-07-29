#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

#include "RungeGutta.hh"

using namespace std;

/*
 * Calculate aritmetic interpolate to real nmber
 * ai = initial number
 * an = final number
 *  n = number of arithmetic means between ai and an
 */
void interpolate_double(double angle[], double ai, double an, double n) {
    double r = (an - ai) / ((n + 2.0f) - 1.0f);
    double v = ai;
    int i = 0;
    do {
        angle[i] = v;
        //cout << i << fixed << setprecision(8) << setw(20) << v << endl;
        v = v + r;
        i++;
    } while (i < (n-1));
    angle[i] = v;
    //cout << i << fixed << setprecision(8) << setw(20) << v;
    //cout << endl;
    return;
}


double runge_kutta_4(double x, double y, double *z, double h)
{
    double k1, k2, k3, k4, l1, l2, l3, l4;

    k1 = h * f(x, y, * z); // método de runge-kutta de ordem 4
    l1 = h * g(x, y, * z);

    k2 = h * f(x + 0.5 * h, y + 0.5 * k1, *z + 0.5 * l1);
    l2 = h * g(x + 0.5 * h, y + 0.5 * k1, *z + 0.5 * l1);

    k3 = h * f(x + 0.5 * h, y + 0.5 * k2, *z + 0.5 * l2);
    l3 = h * g(x + 0.5 * h, y + 0.5 * k2, *z + 0.5 * l2);

    k4 = h * f(x + h, y + k3, *z + l3);
    l4 = h * g(x + h, y + k3, *z + l3);

    y  = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    *z = *z + (l1 + 2 * l2 + 2 * l3 + l4) / 6.0;
    return y;       
}
