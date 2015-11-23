//
//  newton_test.cpp
//  Newton
//
//  Created by Arslan Memon on 9/26/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;
double newton(Fcn& f, Fcn& df, double x, int maxit,
              double tol, bool show_iterates);


//f=x(x-3)(x+1)=x^3-2x^2-3x
class f:public Fcn{
public:
    double operator()(double x) {
        return (((x-2)*x-3)*x);//nested multiplication using horner's method, returns x evaluated by function

    }
};

// f'=3x^2-4x-3
class df:public Fcn{
public:
    double operator()(double x) {
        return (((3)*x-4)*x-3);//nested multiplication using horner's method, returns f' evaluated at x
    }
};


int main(int argc, char* argv[]) {
    f function;// f object called function
    df derivative;// derivative of f object called derivative
    // use newtonm to solve for roots of function. Each newton method uses an initial guess of x=-2,1,2 and each evaluates the roots using tolerance of 10^-1, 10^-5, 10^-9 for each initial guess, thus 9 tests
    newton(function, derivative, -2, 15, 1e-1, true);
    newton(function, derivative, -2, 15, 1e-5, true);
    newton(function, derivative, -2, 15, 1e-9, true);
    newton(function, derivative, 1, 15, 1e-1, true);
    newton(function, derivative, 1, 15, 1e-5, true);
    newton(function, derivative, 1, 15, 1e-9, true);
    newton(function, derivative, 2, 15, 1e-1, true);
    newton(function, derivative, 2, 15, 1e-5, true);
    newton(function, derivative, 2, 15, 1e-9, true);
    
    return 0;

};

