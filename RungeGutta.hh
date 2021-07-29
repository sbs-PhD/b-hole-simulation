#ifndef RungeGutta_hh
#define RungeGutta_hh

void   interpolate_double(double angle[], double ai, double an, double n);

double f(double x, double y, double z); // must apear in main.cc
double g(double x, double y, double z); // must apear in main.cc
double runge_kutta_4(double x, double y, double *z, double h);

#endif // RungeGutta_hh
