//
//  kepler.cpp
//  Newton
//
//  Created by Arslan Memon on 10/4/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"
#include "matrix.hpp"
using namespace std;
double newton(Fcn& f, Fcn& df, double x, int maxit,
              double tol, bool show_iterates);
// kepler equation is sqrt(1-b^2/a^2)sin(w)-w=t, thus a non-linear root finding residual function, f(w) can be founnd by subtracting t, which gives f(w)=sqrt(1-b^2/a^2)sin(w)-w-t=0
class Kepler:public Fcn{
public:
    double t;//modifiable parameter for time
    double operator()(double w) {
        return sqrt(1-(pow(1.25,2)/pow(2.0, 2)))*sin(w)-w-t;//a=2.0, b=1.25, solve the kepler equation at some w
   
   }
 
};
//derivative for kepler equation
class dKepler:public Fcn{
public:
    double operator()(double w) {
        return sqrt(1-(pow(1.25,2)/pow(2.0, 2)))*cos(w)-1;
    }
};

int main(int argc, char* argv[]) {
    Kepler k;//object for kepler function
    dKepler dk;// object for the derivative of kepler function
    Matrix t=Linspace(0, 10,10001);// matrix for time using linspace to get 10001 evenly spaced points between 0 and 10
    double w=0.0;// initial guess for w is 0
    double ab=1.25*2.0;//a*b
    //Matrices to store cartesian coordinates of r(w)
    Matrix x (10001);
    Matrix y(10001);
    for (int i=0;i<10001;i++)
    {
        
        k.t=t(i);// set t
        w= newton(k, dk, w,6 , 1e-5, false);//use newton to get approxiimation of root with 6 iterations man and tolerance of 10^-5. Uses previous w to calculate the new approximation
        double r=ab/sqrt(pow(1.25*cos(w),2)+pow(2.0*sin(w), 2));//calculate r(w)
        x(i)=r*cos(w);//x=rcos(w)
        y(i)=r*sin(w);//y=rsin(w)
        
    }
   //store files to disk
     t.Write("t.txt");
    x.Write("x(t).txt");
    y.Write("y(t).txt");
};
