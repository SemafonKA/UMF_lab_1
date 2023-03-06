#pragma once
#include <vector>
#include <array>
#include <format>
#include <functional>
#include "diagonal_matrix.h"
#include "grid.h"

using MathFunc2d = std::function<double(double, double)>;

class FDMsolver {
public:
   MathFunc2d firstBoundaryAt;
   MathFunc2d secondBoundaryAt;
   MathFunc2d lambdaAt;
   MathFunc2d lambdaDifxAt;
   MathFunc2d lambdaDifyAt;
   MathFunc2d gammaAt;
   MathFunc2d funcAt;

   Grid::Grid& grid;

   FDMsolver(Grid::Grid& grid, MathFunc2d firstBoundaryAt, MathFunc2d secondBoundaryAt, MathFunc2d lambdaAt,
      MathFunc2d lambdaDifxAt, MathFunc2d lambdaDifyAt, MathFunc2d gammaAt, MathFunc2d funcAt) :
      grid{ grid }, firstBoundaryAt{ firstBoundaryAt }, secondBoundaryAt{ secondBoundaryAt }, lambdaAt{ lambdaAt },
      lambdaDifxAt{ lambdaDifxAt }, lambdaDifyAt{ lambdaDifyAt }, gammaAt{ gammaAt }, funcAt{ funcAt } {}

   std::vector<double> solve();
};