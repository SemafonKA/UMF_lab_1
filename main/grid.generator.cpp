#include "grid.generator.h"
#include <cmath>

inline bool isAlmostEq(double _first, double _second, double maxRelDif) {
    double delta = std::abs(_first - _second);
    _first = std::abs(_first); _second = std::abs(_second);
    double maxNum = _first > _second ? _first : _second;
    return delta <= maxNum * maxRelDif;
}

Grid::BoundaryEdge Grid::BoundaryEdge::alongY(double x, double yBegin, double yEnd, BoundaryType type) {
    auto edge = BoundaryEdge();
    edge.xBegin = edge.xEnd = x;
    edge.yBegin = yBegin;
    edge.yEnd = yEnd;
    edge.type = type;
    return edge;
}

Grid::BoundaryEdge Grid::BoundaryEdge::alongX(double y, double xBegin, double xEnd, BoundaryType type) {
   auto edge = BoundaryEdge();
   edge.yBegin = edge.yEnd = y;
   edge.xBegin = xBegin;
   edge.xEnd = xEnd;
   edge.type = type;
   return edge;
}

/// <summary>
/// Функция генерация сетки на основе введённых данных
/// </summary>
/// <returns>Массив из элементов сетки, каждый из которых имеет свой заданный тип</returns>
Grid::Grid Grid::GenerateGrid() {
   Grid grid;        // Сама сетка с узлами, их координатами и типами узлов

   double xFrom;        // Начальная точка Х
   double yFrom;        // Начальная точка Y

   std::vector<GridRange> xRangesComp;      // Сжатая сетка вдоль оси Х
   std::vector<GridRange> yRangesComp;      // Сжатая сетка вдоль оси Y

   std::vector<GridMaskElement> gridMask;   // Маска области

   std::vector<BoundaryEdge> edges;         // Краевые условия

   // Допустим, ввод данных сжатой сетки
   {
      xFrom = 0.0;
      yFrom = 0.0;

      // Равномерная сетка
      //double frac = 2;
      //xRangesComp.push_back(GridRange(3.0, 3.0 / frac));
      //xRangesComp.push_back(GridRange(6.0, 3.0 / frac));
      //xRangesComp.push_back(GridRange(9.0, 3.0 / frac));

      //yRangesComp.push_back(GridRange(3.0, 3.0 / frac));
      //yRangesComp.push_back(GridRange(6.0, 3.0 / frac));

      // Неравномерная сетка с постоянным шагом в каждой области
      //double frac = 1;
      //xRangesComp.push_back(GridRange(3.0, 3.0 / frac));
      //xRangesComp.push_back(GridRange(6.0, 1.5 / frac));
      //xRangesComp.push_back(GridRange(9.0, 3.0 / frac));

      //yRangesComp.push_back(GridRange(3.0, 3.0 / frac));
      //yRangesComp.push_back(GridRange(5.0, 1.5 / frac));
       
      // Неравномерная сетка
      //xRangesComp.push_back(GridRange(3.0, 3.0));
      //xRangesComp.push_back(GridRange(6.0, 1.0, 2.0));
      //xRangesComp.push_back(GridRange(9.0, 3.0));

      //yRangesComp.push_back(GridRange(3.0, 1.0, 2.0));
      //yRangesComp.push_back(GridRange(6.5, 0.5, 2.0));

      // Сетка с одной областью
      //double frac = 2.0;
      //xRangesComp.push_back(GridRange(6.0, 6.0 / frac));
      //yRangesComp.push_back(GridRange(6.0, 6.0 / frac));
      
      // Сетка с одной областью для синуса
      double frac = 4.0;
      xRangesComp.push_back(GridRange(1.0, 1.0 / frac));
      yRangesComp.push_back(GridRange(1.0, 1.0 / frac));
   }

   // Считываем маску сетки
   {
      // Маска равномерной и неравномерной сеток
      //gridMask.push_back(GridMaskElement::fictive());
      //gridMask.push_back(GridMaskElement());
      //gridMask.push_back(GridMaskElement::fictive());
      //gridMask.push_back(GridMaskElement());
      //gridMask.push_back(GridMaskElement());
      //gridMask.push_back(GridMaskElement());

      // Маска сетки с одной областью
      gridMask.push_back(GridMaskElement());
   }

   // Считываем краевые условия
   {
      // Для равномерной сетки
      //edges.push_back(BoundaryEdge::alongX(0.0, 3.0, 6.0));
      //edges.push_back(BoundaryEdge::alongY(3.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongY(6.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongX(3.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongX(3.0, 6.0, 9.0));
      //edges.push_back(BoundaryEdge::alongY(0.0, 3.0, 6.0));
      //edges.push_back(BoundaryEdge::alongY(9.0, 3.0, 6.0));
      //edges.push_back(BoundaryEdge::alongX(6.0, 0.0, 9.0));

      // Для неравномерной сетки с постоянным шагом
      //edges.push_back(BoundaryEdge::alongX(0.0, 3.0, 6.0));
      //edges.push_back(BoundaryEdge::alongY(3.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongY(6.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongX(3.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongX(3.0, 6.0, 9.0));
      //edges.push_back(BoundaryEdge::alongY(0.0, 3.0, 5.0));
      //edges.push_back(BoundaryEdge::alongY(9.0, 3.0, 5.0));
      //edges.push_back(BoundaryEdge::alongX(5.0, 0.0, 9.0));

      // Для неравномерной сетки
      //edges.push_back(BoundaryEdge::alongX(0.0, 3.0, 6.0));
      //edges.push_back(BoundaryEdge::alongY(3.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongY(6.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongX(3.0, 0.0, 3.0));
      //edges.push_back(BoundaryEdge::alongX(3.0, 6.0, 9.0));
      //edges.push_back(BoundaryEdge::alongY(0.0, 3.0, 6.5));
      //edges.push_back(BoundaryEdge::alongY(9.0, 3.0, 6.5));
      //edges.push_back(BoundaryEdge::alongX(6.5, 0.0, 9.0));

      // Для сетки из одной области
      //edges.push_back(BoundaryEdge::alongX(0.0, 0.0, 6.0));
      //edges.push_back(BoundaryEdge::alongX(6.0, 0.0, 6.0));
      //edges.push_back(BoundaryEdge::alongY(0.0, 0.0, 6.0));
      //edges.push_back(BoundaryEdge::alongY(6.0, 0.0, 6.0));

      // Для сетки из одной области для синусов
      edges.push_back(BoundaryEdge::alongX(0.0, 0.0, 1.0));
      edges.push_back(BoundaryEdge::alongX(1.0, 0.0, 1.0));
      edges.push_back(BoundaryEdge::alongY(0.0, 0.0, 1.0));
      edges.push_back(BoundaryEdge::alongY(1.0, 0.0, 1.0));
   }

   // Декомпрессируем сетку, записываем индексы границ каждой сетки, заодно проверяем на то, чтобы она совпадала по шагам с границами
   std::vector<double> xRanges = { xFrom };
   std::vector<double> yRanges = { yFrom };
   // Сначала по иксам
   auto prevValue = xFrom;
   for (std::size_t i = 0; i < xRangesComp.size(); i++) {
      const auto& range = xRangesComp.at(i);
      std::size_t indBegin = xRanges.size() - 1;

      // Обработка для сеток без умножения на шаг
      if (!range.isMultiplied()) {
         auto step = range.firstStep;
         auto stepCounts = (range.to - prevValue) / step;
         // Если число шагов не совпадает со своим округлением
         if (!isAlmostEq(stepCounts, round(stepCounts))) {
            throw std::runtime_error(
               std::format("Диапазон по оси Х [to:{},step:{},mult:{}] не попадает по шагу в конец диапазона.", range.to, range.firstStep, range.stepMultiplier)
            );
         }
         stepCounts = round(stepCounts);
         double currentValue;
         for (size_t i = 0; i < stepCounts; i++) {
            currentValue = prevValue + (i + 1) * step;
            xRanges.push_back(currentValue);
         }
         prevValue = range.to;
      }
      else { // Костыль для сеток с вычисляемым шагом
         // Находим крайнее значение, которое на следующем шаге станет близко к [range.to], либо которое превысит [range.to]
         auto currentStep = range.firstStep;
         while (prevValue < range.to && !isAlmostEq(prevValue + currentStep, range.to)) {
            prevValue += currentStep;
            currentStep *= range.stepMultiplier;

            xRanges.push_back(prevValue);
         }
         // Если значение + шаг не близко к range.to, то сетка не совпадает
         if (!isAlmostEq(prevValue + currentStep, range.to)) {
            throw std::runtime_error(
               std::format("Диапазон по оси Х [to:{},step:{},mult:{}] не попадает по шагу в конец диапазона.", range.to, range.firstStep, range.stepMultiplier)
            );
         }

         // В конце присваиваем конец сетки для исключения погрешностей
         prevValue = range.to;
         xRanges.push_back(prevValue);
      }

      // Создаём соответствие масок и индексов полноценной сетки
      std::size_t indEnd = xRanges.size();
      for (std::size_t j = i; j < gridMask.size(); j += xRangesComp.size()) {
         gridMask.at(j).xBeginInd = indBegin;
         gridMask.at(j).xEndInd = indEnd;
      }
   }
   // Затем по игрекам
   prevValue = yFrom;
   for (std::size_t i = 0; i < yRangesComp.size(); i++) {
      const auto& range = yRangesComp.at(i);
      std::size_t indBegin = yRanges.size() - 1;

      // Обработка для сеток без умножения на шаг
      if (!range.isMultiplied()) {
         auto step = range.firstStep;
         auto stepCounts = (range.to - prevValue) / step;
         // Если число шагов не совпадает со своим округлением
         if (!isAlmostEq(stepCounts, round(stepCounts))) {
            throw std::runtime_error(
               std::format("Диапазон по оси Y [to:{},step:{},mult:{}] не попадает по шагу в конец диапазона.", range.to, range.firstStep, range.stepMultiplier)
            );
         }
         stepCounts = round(stepCounts);
         double currentValue;
         for (size_t i = 0; i < stepCounts; i++) {
            currentValue = prevValue + (i + 1) * step;
            yRanges.push_back(currentValue);
         }
         prevValue = range.to;
      }
      else {
         auto currentStep = range.firstStep;
         while (prevValue < range.to && !isAlmostEq(prevValue + currentStep, range.to)) {
            prevValue += currentStep;
            currentStep *= range.stepMultiplier;

            yRanges.push_back(prevValue);
         }
         if (!isAlmostEq(prevValue + currentStep, range.to)) {
            throw std::runtime_error(
               std::format("Диапазон по оси Y [to:{},step:{},mult:{}] не попадает по шагу в конец диапазона.", range.to, range.firstStep, range.stepMultiplier)
            );
         }
         prevValue = range.to;
         yRanges.push_back(prevValue);
      }

      std::size_t indEnd = yRanges.size();
      for (std::size_t j = 0; j < xRangesComp.size(); j++) {
         gridMask.at(i * xRangesComp.size() + j).yBeginInd = indBegin;
         gridMask.at(i * xRangesComp.size() + j).yEndInd = indEnd;
      }
   }

   auto xStepsCount = xRanges.size();
   auto yStepsCount = yRanges.size();

   grid.sizeX = xStepsCount;
   grid.sizeY = yStepsCount;
   grid.data.resize(xStepsCount * yStepsCount);

   // Заполняем сетку, обозначаем узлы фиктивными или не фиктивными
   for (const auto& gridMaskElem : gridMask) {
      for (std::size_t i = gridMaskElem.yBeginInd; i < gridMaskElem.yEndInd; i++) {
         for (std::size_t j = gridMaskElem.xBeginInd; j < gridMaskElem.xEndInd; j++) {
            auto& node = grid.data.at(i * xStepsCount + j);
            if (node.type == NodeType::undefined) {
               node.coordX = xRanges.at(j);
               node.coordY = yRanges.at(i);
               if (j > 0) {
                  node.leftNode = &(grid.data.at(i * xStepsCount + j - 1));
               }
               if (j + 1 < xStepsCount) {
                  node.rightNode = &(grid.data.at(i * xStepsCount + j + 1));
               }
               if (i > 0) {
                  node.bottomNode = &(grid.data.at((i - 1) * xStepsCount + j));
               }
               if (i + 1 < yStepsCount) {
                  node.topNode = &(grid.data.at((i + 1) * xStepsCount + j));
               }
               if (gridMaskElem.isFictive) {
                  node.type = NodeType::fictive;
               }
               else {
                  node.type = NodeType::normal;
               }
            }
            else if (node.type == NodeType::fictive && !gridMaskElem.isFictive) {
               node.type = NodeType::normal;
            }
         }
      }
   }

   // Задаём краевые условия:
   for (const auto& edge : edges) {
      // Находим нужный узел
      std::size_t yInd = 0;
      while (yInd < yStepsCount && grid.data.at(yInd * xStepsCount).coordY != edge.yBegin) { yInd++; }
      if (yInd == yStepsCount) {
         throw std::runtime_error(std::format("Начало краевого условия задано за пределами сетки: xBegin={}, yBegin={}",
            edge.xBegin, edge.yBegin));
      }
      std::size_t xInd = 0;
      while (xInd < xStepsCount && grid.data.at(yInd * xStepsCount + xInd).coordX != edge.xBegin) { xInd++; }
      if (xInd == xStepsCount) {
         throw std::runtime_error(std::format("Начало краевого условия задано за пределами сетки: xBegin={}, yBegin={}",
            edge.xBegin, edge.yBegin));
      }
      auto* node = &(grid.data.at(yInd * xStepsCount + xInd));

      // Заполняем все узлы вдоль оси заданного краевого условия
      while (node != nullptr && node->coordX <= edge.xEnd && node->coordY <= edge.yEnd) {
         switch (edge.type)
         {
         case BoundaryType::first:
            node->type = NodeType::firstBoundary;
            break;

         case BoundaryType::second:
            node->type = NodeType::secondBounary;
            break;
         }
         if (edge.isAlongX()) {
            node = node->rightNode;
         }
         else {
            node = node->topNode;
         }
      }
   }

   return grid;
}

inline Grid::GridMaskElement Grid::GridMaskElement::fictive() {
   auto elem = GridMaskElement();
   elem.isFictive = true;
   return elem;
}
