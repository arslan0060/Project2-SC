//
//  test_fd_newton.cpp
//  Newton
//
//  Created by Arslan Memon on 9/28/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;

double fd_newton(Fcn& f, double x, int maxit, double tol, double alpha, bool show_iterates);



class f:public Fcn{
public:
    double operator()(double x) {//same f as in newton.cpp
        return (((x-2)*x-3)*x);
        
    }
};

int main(int argc, char* argv[]) {
    f function;
    //same evaluations as newton.cpp, but each evaluation is done three times for different alphas of 2^-4, 2^-26, 2^-50, prints out the calculations in each iteration
    fd_newton(function,-2, 20, 1e-1,pow(2, -4),true);
    fd_newton(function,-2, 20, 1e-1,pow(2, -26),true);
    fd_newton(function,-2, 20, 1e-1,pow(2, -50),true);
    cout<<endl;
    fd_newton(function,-2, 20, 1e-5,pow(2, -4),true);
    fd_newton(function,-2, 20, 1e-5,pow(2, -26),true);
    fd_newton(function,-2, 20, 1e-5,pow(2, -50),true);
    cout<<endl;
    fd_newton(function,-2, 20, 1e-9, pow(2, -4),true);
    fd_newton(function,-2, 20, 1e-9, pow(2, -26), true);
    fd_newton(function,-2, 20, 1e-9, pow(2, -50), true);
    cout<<endl;
    fd_newton(function, 1, 20, 1e-1, pow(2,-4), true);
    fd_newton(function, 1, 20, 1e-1, pow(2,-26), true);
    fd_newton(function, 1, 20, 1e-1, pow(2,-50), true);
    cout<<endl;
    fd_newton(function, 1, 20, 1e-5, pow(2, -4), true);
    fd_newton(function, 1, 20, 1e-5, pow(2, -26), true);
    fd_newton(function, 1, 20, 1e-5, pow(2, -50), true);
    cout<<endl;
    fd_newton(function, 1, 20, 1e-9, pow(2, -4), true);
    fd_newton(function, 1, 20, 1e-9, pow(2, -26), true);
    fd_newton(function, 1, 20, 1e-9, pow(2, -50), true);
    cout<<endl;
    fd_newton(function, 2, 20, 1e-1, pow(2, -4), true);
    fd_newton(function, 2, 20, 1e-1, pow(2, -26), true);
    fd_newton(function, 2, 20, 1e-1, pow(2, -50), true);
    cout<<endl;
    fd_newton(function, 2, 20, 1e-5, pow(2, -4), true);
    fd_newton(function, 2, 20, 1e-5, pow(2, -26), true);
    fd_newton(function, 2, 20, 1e-5, pow(2, -50), true);
    cout<<endl;
    fd_newton(function, 2, 20, 1e-9,pow(2,-4), true);
    fd_newton(function, 2, 20, 1e-9,pow(2,-26), true);
    fd_newton(function, 2, 20, 1e-9,pow(2,-50), true);
    cout<<endl;
    return 0;
    
};
