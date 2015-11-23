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
              double tol, bool show_iterates)
{
    if (maxit<1)
    {
        std::cerr<<"not enough iterations, returning input value"<<std::endl;
        return x;
    }
    if (tol<1e-15)
    {
        std::cerr<<"tol<1e-15, resetting to to 1e-15"<<std::endl;
        tol=1e-15;
    
    }
    double fx=f(x);
    if (show_iterates)
    {
        std::cout<<"|fx|="<<fabs(fx)<<std::endl;
    
    }
    for (int n=0;n<maxit;n++)
    {
        double fp=df(x);
        
        if (fabs(fp)<1e-15)
        {
            std::cout<<"small derivative";
            return x;
        }
        double d=fx/fp;
        x=x-d;
        fx=f(x);
        if( show_iterates)
        {
        
            std::cout<<"iteration="<<n<<", x="<<x<<", |d|="<<fabs(d)<<", |fx|= "<<fabs(fx)<<std::endl;
        }
        if (fabs(d)<tol)
        {
            return x;
        
        }
    }
    return x;

}