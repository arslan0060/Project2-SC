//
//  newton.cpp
//  Newton
//
//  Created by Arslan Memon on 9/26/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

double newton(Fcn& f, Fcn& df, double x, int maxit,
              double tol, bool show_iterates)//newton root finding
{
    if (maxit<1)// if iterartions is <1, then just return x
    {
        std::cerr<<"not enough iterations, returning input value"<<std::endl;
        return x;
    }
    if (tol<1e-15)//reset tolerance if tolerance is too low
    {
        std::cerr<<"tol<1e-15, resetting to to 1e-15"<<std::endl;
        tol=1e-15;
    
    }
    double fx=f(x);//calculate f(x)
    if (show_iterates)// print initial guess and initial evaluation if show iterates
    {
        std::cout<<"Initial guess x="<<x<<", |fx|="<<fabs(fx)<<", tolerance= "<<tol<<std::endl;
    
    }
    for (int n=0;n<maxit;n++)//loop to find root
    {
        double fp=df(x);// calculate f'
        
        if (fabs(fp)<1e-15)// if the absolute value of f'< tol, return x because that means the slope is close to 0, so it will never reach the intersection
        {
            std::cout<<"small derivative";
            return x;
        }
        double d=fx/fp;// d is the correction amount that need to be subtracted from x
        x=x-d;
        fx=f(x);//new f(x)
        if( show_iterates)//show detail for iteration
        {
        
            std::cout<<"iteration="<<n<<", x="<<x<<", |d|="<<fabs(d)<<", |fx|= "<<fabs(fx)<<std::endl;
        }
        if (fabs(d)<tol)//if correction < tol, then  return x
        {
            return x;
        
        }
    }
    return x;

}