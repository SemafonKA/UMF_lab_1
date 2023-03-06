#pragma once

#include <vector>
#include <format>
#include <float.h>

#include "grid.h"

inline bool isAlmostEq(double _first, double _second, double maxRelDif = DBL_EPSILON * 10.0);

namespace Grid {
   class GridRange {
   public:
      double to = 0.0;
      double firstStep = 0.0;
      double stepMultiplier = 1.0;

      GridRange(double to, double firstStep, double stepMult = 1.0) :
         to(to), firstStep(firstStep), stepMultiplier(stepMult) {}

      bool isMultiplied() const { return stepMultiplier == 1.0; };
   };

   class GridMaskElement {
   public:
      bool isFictive = false;

      std::size_t xBeginInd = 0;
      std::size_t xEndInd = 0;
      std::size_t yBeginInd = 0;
      std::size_t yEndInd = 0;

      static GridMaskElement fictive();
   };

   enum class BoundaryType {
      first,
      second,
   };

   class BoundaryEdge {
   public:
      BoundaryType type = BoundaryType::first;

      double xBegin = 0.0;
      double xEnd = 0.0;
      double yBegin = 0.0;
      double yEnd = 0.0;

      inline bool isAlongX() const { return yBegin == yEnd; }
      inline bool isAlongY() const { return xBegin == xEnd; }

      static BoundaryEdge alongY(double x, double yBegin, double yEnd, BoundaryType type = BoundaryType::first);
      static BoundaryEdge alongX(double y, double xBegin, double xEnd, BoundaryType type = BoundaryType::first);
   };

   /// <summary>
   /// Функция генерация сетки на основе введённых данных
   /// </summary>
   /// <returns>Массив из элементов сетки, каждый из которых имеет свой заданный тип</returns>
   Grid GenerateGrid();
}