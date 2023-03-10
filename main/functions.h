#pragma once

#include <cmath>

//double firstBoundaryAt(double x, double y) {
//   return sin(x+y);
//}
//
//double secondBoundaryAt(double x, double y) {
//   return 0.0;
//}
//
//double lambdaAt(double x, double y) {
//   return 1.0;
//}
//
//double lambdaDifxAt(double x, double y) {
//   return 0.0;
//}
//
//double lambdaDifyAt(double x, double y) {
//   return 0.0;
//}
//
//double gammaAt(double x, double y) {
//   return 1.0;
//}
//
//double funcAt(double x, double y) {
//   return 3*sin(x+y);
//}

// double firstBoundaryAt(double x, double y) {
//    return x * x * x * x + y * y * y * y;
//}
//
//double secondBoundaryAt(double x, double y) {
//   return 0.0;
//}
//
//double lambdaAt(double x, double y) {
//   return 1.0;
//}
//
//double lambdaDifxAt(double x, double y) {
//   return 0.0;
//}
//
//double lambdaDifyAt(double x, double y) {
//   return 0.0;
//}
//
//double gammaAt(double x, double y) {
//   return 1.0;
//}
//
//double funcAt(double x, double y) {
//   return x*x*x*x + y*y*y*y - 12.0*x*x - 12.0*y*y;
//}


double firstBoundaryAt(double x, double y) {
   return x * x * x + y * y * y;
}

double secondBoundaryAt(double x, double y) {
   return 0.0;
}

double lambdaAt(double x, double y) {
   return 1.0;
}

double lambdaDifxAt(double x, double y) {
   return 0.0;
}

double lambdaDifyAt(double x, double y) {
   return 0.0;
}

double gammaAt(double x, double y) {
   return 1.0;
}

double funcAt(double x, double y) {
   return x * x * x + y * y * y - 6.0 * x - 6.0 * y;
}