#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

#include "GnuPlotGraph.hh"
#include "RungeGutta.hh"
#include "physical_constants.hh"

#define NumSolarMass 3.0
#define NumPoints   1000
#define J 2

using namespace std;

double f(double x, double y, double z)
{
    return z;  // differential equation: dy/dx=f(x,y,z)
}

double g(double x, double y, double z)
{
    double rS = (2.0 * G * NumSolarMass * SolarMass) / (c * c);
    double kappa = (3.0 / 2.0) * rS;
    return( kappa * (y * y) - y );  // differential equation: dz/dx=g(x,y,z)
}

int main(int argc, char** argv)
{
    double * phi_range = new double[NumPoints];
    
    /* Schwarzschild */
    double r_phi0[3] = {1.499, 1.500, 1.501};
    double k[3]      = {1.5, 1.0, 1.1};
    string fig[3]    = {"fig01-si", "fig02-si", "fig03-si"};
    
    double phi0 = 0.0;
    double rS = (2.0 * G * NumSolarMass * SolarMass) / (c * c);
    double var0 = 1.0 / (r_phi0[J] * rS);
    
    interpolate_double(phi_range, phi0, (k[J] * 2.0 * PI), NumPoints); // fills with angles between zero e 2*K*PI, where K is the period.
    
    //cout << "Schwarzschild Black Hole" << endl;
    //cout << "------------------------" << endl;
    //cout << " Radius: " << fixed << setprecision(8) << setw(20) << rS << endl;
    //cout << "  kappa: " << fixed << setprecision(8) << setw(20) << kappa << endl;
    //cout << "r(phi0): ";
    //for(int i=0; i < 3; i++) cout << fixed << setprecision(8) << setw(20) << r_phi0[i] << " " ;
    //cout << endl;
    //cout << "    fig: ";
    //for(int i=0; i < 3; i++) cout << fig[i] << " ";
    //cout << endl;
    //cout << "   var0: " << fixed << setprecision(8) << setw(20) << var0 << endl;
    
    double z0, xmax, h; // input vars
    double xn, yn, *zn; // increment vars
    
    z0 = 0;
    xmax = NumPoints;
    h = phi_range[1] - phi_range[0];
    
    ofstream fp;
    string strtmp = fig[J] + ".dat";
    fp.open(strtmp);
    
    double x0 = 0.0;
    double y0 = 0.0;
    int j = 0;
    xn = phi_range[j];
    yn = var0;
    zn = &z0;
    do
    {
        /* Schwarzschild */
        yn = runge_kutta_4(xn, yn, zn, h);
        xn = phi_range[j]; //xn + h;
        
        /* Parametric */
        y0 = sin(xn) / yn /rS;
        x0 = cos(xn) / yn /rS;
        
        fp << fixed << setprecision(8) << setw(20) << x0 << "," << fixed << setprecision(8) << setw(20) << y0 << endl;
        
        j+=1;
    }
    while(j < NumPoints);
    
    fp.close();
    
    string str = fig[J];
    script_gnuplot(str.c_str());
    
    str = "gnuplot " + str + ".plt";
    const char *command = str.c_str();
    system(command);
    
    str = fig[J];
    script_gnuplot(str.c_str());
    postscript2jpeg(str.c_str());
    
    return 0;
}
// EOF
