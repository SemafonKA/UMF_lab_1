#pragma once
#include <vector>
#include <array>
#include <format>
#include <functional>
#include "diagonal_matrix.h"
#include "grid.h"

using MathFunc2d = std::function<double(double, double)>;
using mathRegFunc2d = std::function<double(int, double, double)>;

class FDMsolver {
public:
   mathRegFunc2d firstBoundaryAt;
   mathRegFunc2d secondBoundaryAt;
   mathRegFunc2d thirdBoundaryAt;
   mathRegFunc2d thirdBoundaryBetaAt;
   MathFunc2d lambdaAt;
   MathFunc2d lambdaDifxAt;
   MathFunc2d lambdaDifyAt;
   MathFunc2d gammaAt;
   MathFunc2d funcAt;

   Grid::Grid& grid;

   FDMsolver(Grid::Grid& grid,
      mathRegFunc2d firstBoundaryAt,
      mathRegFunc2d secondBoundaryAt,
      mathRegFunc2d thirdBoundaryAt,
      mathRegFunc2d thirdBoundaryBetaAt,
      MathFunc2d lambdaAt,
      MathFunc2d lambdaDifxAt,
      MathFunc2d lambdaDifyAt,
      MathFunc2d gammaAt,
      MathFunc2d funcAt)
      :
      grid{ grid },
      firstBoundaryAt{ firstBoundaryAt },
      secondBoundaryAt{ secondBoundaryAt },
      thirdBoundaryAt{ thirdBoundaryAt },
      thirdBoundaryBetaAt{ thirdBoundaryBetaAt },
      lambdaAt{ lambdaAt },
      lambdaDifxAt{ lambdaDifxAt },
      lambdaDifyAt{ lambdaDifyAt },
      gammaAt{ gammaAt },
      funcAt{ funcAt }
   {}

   std::vector<double> solve();
};