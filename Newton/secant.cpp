/* Daniel R. Reynolds
   SMU Mathematics
   Math 3316
   16 September 2015 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;

// This routine solves the scalar-valued nonlinear equation f(x)=0 
// using the Secant method to a solution tolerance of tol.
//
// Usage: x = secant(f, x, x0, maxit, tol, show_iterates);
//
// inputs:   f              user-supplied Fcn object
//           x              initial guess [double]
//           x0             extra initial guess [double]
//           maxit          maximum allowed iterations [int]
//           tol            solution tolerance [double]
//           show_iterates  display/hide iteration information [bool]
// outputs:  x              approximate solution [double]
// 
double secant(Fcn& f, double x, double x0, int maxit, 
	      double tol, bool show_iterates) {

  // check input arguments
  if (maxit < 1) {
    cerr << "warning: maxit = " << maxit << " < 1. Resetting to 100\n";
    maxit = 100;
  }
  if (tol < 1.e-15) {
    cerr << "warning: tol is too small, resetting to 1e-15\n";
    tol = 1.e-15;
  }
  if (fabs(x-x0) < 1.e-15*fabs(x)) {
    cerr << "warning: guesses are too similar, shifting x0\n";
    x0 += 1.e-15*fabs(x);
  }

  // get initial function value, size
  double fx  = f(x);
  double fx0 = f(x0);
  if (show_iterates)
    cout << " Secant Method: initial |f(x)| = " << fabs(fx) 
	 << " |f(x0)| = " << fabs(fx0) << endl;

  // begin iteration
  double h, Dfx;
  for (int i=0; i<maxit; i++) {
   
    // update Secant guess
    Dfx = (fx - fx0)/(x-x0);
    if (fabs(Dfx) < 1e-15) 
      cerr << "   Warning: nearly singular, Df(x) = " << Dfx << endl;
   
    // update state, old data, new function value
    h = fx/Dfx;
    x0 = x;
    fx0 = fx;
    x = x - h;
    fx = f(x);
   
    // output convergence information
    if (show_iterates)
      cout << "   iter " << i << ", x = " << x 
	   << ", |h| = " << fabs(h) 
	   << ", |f(x)| = " << fabs(fx) << endl;
    if (fabs(h) < tol)  break;

  } // end loop

  // return final result
  return x;

} // end of function
