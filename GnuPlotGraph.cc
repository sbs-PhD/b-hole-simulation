#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "GnuPlotGraph.hh"

using namespace std;

void postscript2jpeg(const char *filename)
{
    char str[250] = "gs -sDEVICE=jpeg -dJPEGQ=100 -dNOPAUSE -dBATCH -dSAFER -r300 -sOutputFile=";
    strcat(str, filename);
    strcat(str, ".jpg ");
    strcat(str, filename);
    strcat(str, ".ps");
    //cout << str << endl;
    //const char *command = str;
    system(str);

    return;
}

void script_gnuplot(const char *filename) //, const char *legend) {
{   
    double minx = -2.0;
    double maxx =  2.0;
    double miny = -2.0;
    double maxy =  2.0;
    
    ofstream fp;
    
    string str = filename;
    str += ".plt";
    const char *file = str.c_str();
    
    fp.open(file);
    
    fp << "#!/usr/bin/gnuplot" << endl;
    fp << "reset" << endl;
    // fp << "set title \"r=%5.3f\" \n", r);
    fp << "set xlabel \"r/GM\"" << endl;
    fp << "set ylabel \"r/GM\"" << endl;
    
    fp << "set size ratio -1" << endl;
    fp << "unset key" << endl;
    fp << "unset xtics" << endl;
    fp << "unset ytics" << endl;
    fp << "set xtics format \" \"" << endl;
    fp << "set ytics format \" \"" << endl;
    
    fp << "set xrange [" << minx << ":" << maxx << "]" << endl;
    fp << "set yrange [" << miny << ":" << maxy << "]" << endl;
    
    fp << "set style line 1 lt 1 lc rgb \"#0c0887\"" << endl;
    
    // create a black circle at center (0.5, 0.5) with radius 1.0
    fp << "set object 1 circle at 0,0 size 1.0 fillcolor rgb \"black\" linewidth 1 dashtype 3" << endl;
    fp << "plot \"" << filename << ".dat\" using ($1):($2) w l ls 1" << endl;
    
    // ----------
    //     fp << "set terminal jpeg" << endl; // set term jpeg size 1200, 800
    //     fp << "set output \"" << filename  << ".jpg\"" << endl;
    // ----------
    fp << "set terminal postscript landscape enhanced color dashed linewidth 1 \"Helvetica\" 14" << endl;
    fp << "set output  \"" << filename  << ".ps\"" << endl;
    // ----------
    fp << "replot" << endl;
    fp << "unset output" << endl;
    fp << "unset terminal" << endl;
    
    //     fp << "set output" << endl;
    //     fp << "set terminal wxt" << endl;
    //     fp << "replot" << endl;
    //     fp << "pause -1" << endl;
    
    fp.close();
    return;
}
