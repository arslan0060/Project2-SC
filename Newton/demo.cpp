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

// function prototypes
double bisection(Fcn& f, double a, double b, int maxit, 
		 double tol, bool show_iterates);
double newton(Fcn& f, Fcn& df, double x, int maxit, 
	      double tol, bool show_iterates);
double secant(Fcn& f, double x, double x0, int maxit, 
	      double tol, bool show_iterates);

// Root-finding residual function 1
class fcn1 : public Fcn {
public:
  double p;                     // internal parameter
  double operator()(double x) {   // function evaluation
    return (cos(x)*cosh(x) - p);
  }
};

// Derivative of root-finding residual function 1
class dfcn1 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (cos(x)*sinh(x) - sin(x)*cosh(x));
  }
};

// Root-finding residual function 2
class fcn2 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (atan(x));
  }
};

// Derivative of root-finding residual function 2
class dfcn2 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (1.0/(1.0+x*x));
  }
};

// Root-finding residual function 3
class fcn3 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (3.0*x*x*x + x*x - 15.0*x + 3.0);
  }
};

// Derivative of root-finding residual function 3
class dfcn3 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (9.0*x*x + 2.0*x - 15.0);
  }
};

// Root-finding residual function 4
class fcn4 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (x*x*x - 2.0*x*x + x - 3.0);
  }
};

// Derivative of root-finding residual function 4
class dfcn4 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (3.0*x*x - 4.0*x + 1.0);
  }
};
  


// This routine compares the Bisection, Newton and Secant 
// methods on a set of nonlinear root-finding problems.
int main(int argc, char* argv[]) {

  // general parameters
  int maxit_b = 1000000;
  int maxit_n = 100;

  //// TEST 1 ////
  cout << "\nf1(x) = cos(x)*cosh(x)+1:\n\n";

  // set up the Fcn objects for f1
  fcn1 f1;
  f1.p = -1.0;
  dfcn1 df1;

  // call methods with looser tolerance, output results to screen
  double tol = 1e-5;
  cout << "tol = " << tol << endl;
  cout << "\n Bisection, [1,2]:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  double x_b = bisection(f1, 1.0, 2.0, 1000000, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Newton, x0 = 1.5:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  double x_n = newton(f1, df1, 1.5, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Secant, x0 = 1.5, x1 = 1.4:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  double x_s = secant(f1, 1.5, 1.4, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();

  // call methods with tighter tolerance, output results to screen
  tol = 1e-9;
  cout << "same problem, but with tighter tol = " << tol << endl;
  cout << "\n Bisection, [1,2]:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_b = bisection(f1, 1.0, 2.0, 1000000, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << " Newton, x0 = 1.5:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_n = newton(f1, df1, 1.5, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Secant, x0 = 1.5, x1 = 1.4:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_s = secant(f1, 1.5, 1.4, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();


  //// TEST 2 ////
  cout << "\nf2(x) = atan(x):\n\n";
  fcn2 f2;
  dfcn2 df2;

  // call methods
  tol = 1e-5;
  cout << "\n Bisection, [-5,10]:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_b = bisection(f2, -5.0, 10.0, 1000000, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Newton, x0 = 1.3:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_n = newton(f2, df2, 1.3, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Newton, x0 = 1.4:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_n = newton(f2, df2, 1.4, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Secant, x0 = 1.3, x1 = 1.4:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_s = secant(f2, 1.3, 1.4, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();


  //// TEST 3 ////
  cout << "\nf3(x) = 3*x^3 + x^2 - 15*x + 3:\n\n";
  fcn3 f3;
  dfcn3 df3;

  // call methods
  tol = 1e-5;
  cout << "\n Bisection, [-3,3]:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_b = bisection(f3, -3.0, 3.0, 1000000, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Bisection, [1,3]:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_b = bisection(f3, 1.0, 3.0, 1000000, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Newton, x0 = 0:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_n = newton(f3, df3, 0.0, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Newton, x0 = 1.1:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_n = newton(f3, df3, 1.1, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Newton, x0 = 2:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_n = newton(f3, df3, 2.0, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Secant, x0 = 1.1, x1 = 1.2:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_s = secant(f3, 1.1, 1.2, 100, tol, true);


  //// TEST 4 ////
  cout << "\nf4(x) = x^3 - 2*x^2 + x - 3:\n\n";
  fcn4 f4;
  dfcn4 df4;

  // call methods
  tol = 1e-5;
  cout << "\n Bisection, [-5,5]:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_b = bisection(f4, -5.0, 5.0, 1000000, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Newton, x0 = 0:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_n = newton(f4, df4, 0.0, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Secant, x0 = 0.0, x1 = 0.1:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_s = secant(f4, 0.0, 0.1, 100, tol, true);
  cout << "   Paused, press [enter] to continue";  cin.get();
  cout << "\n Secant, x0 = 0.0, x1 = 0.01:\n";
  cout << "   Paused, press [enter] to continue";  cin.get();
  x_s = secant(f4, 0.0, 0.01, 100, tol, true);


}


