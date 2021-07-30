#ifndef physical_constants_hh
#define physical_constants_hh

#include <cmath>
#include <string>
#include <vector>

/*
 * 2. Astrophysical Constants and Parameters - Table 2.1 in
 * P. A. Zyla et al. (Particle Data Group), Prog. Theor. Exp. Phys. 2020, 083C01 (2020).
 */

static const double PI        = 3.141592653589793238;
static const double c         = 299792458.0;  // m s−1 // speed of light in vacuum
static const double SolarMass = 1.98841e30; // kg // Solar mass PDG 2020
static const double G         = 6.67430e-11;  // m3 k g−1 s−2  // Newtonian constant of gravitation

static const double h         = 6.626070e-34; // J s (or J/Hz) Planck constant
static const double hbar      = 1.054571628e-34; // Js // Planck constant, reduced
// static const double hbar = 6.58211899e-22 // MeV s
//static const double Kb = 5.670400e-8; // W m−2 K−4 // Stefan-Boltzmann constant
static const double KB        = 1.3806504e-23; // J K-1 // Boltzmann constant
#endif
