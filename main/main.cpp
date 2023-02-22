#include <iostream>
#include <vector>
#include <format>

using namespace std;

class Todo : public runtime_error {
public:
   Todo(string str) : runtime_error(str) {}
};

inline bool isAlmostEq(double _first, double _second, double maxRelDif = DBL_EPSILON * 10.0) {
   double delta = abs(_first - _second);
   _first = abs(_first); _second = abs(_second);
   double maxNum = _first > _second ? _first : _second;
   return delta <= maxNum * maxRelDif;
}

double Norm(const vector<double>& X)
{
   double norma = 0;
   for (size_t i = 0; i < X.size(); i++)
   {
      norma += X[i] * X[i];
   }
   norma = sqrt(norma);
   return norma;
}

class DiagonalMatrix {
public:
   vector<vector<double>> diags;

   vector<int> diagsShift;

   void setForm(size_t size, vector<int> shifts) {
      if ((shifts.size() & 1) != 1) {
         throw runtime_error("Number of diags must be the odd");
      }

      diagsShift = move(shifts);

      diags.resize(diagsShift.size());
      for (auto& diag : diags) {
         diag.resize(size);
      }
   }

   size_t size() {
      if (diags.empty()) {
         throw runtime_error("Matrix is not formed!");
      }
      return diags.at(0).size();
   }

   size_t wide() {
      return diags.size();
   }

   size_t zeidellSolve(const vector<double>& vecB, vector<double>& vecX, double& oDif, double relaxCoef = 0.5,
      size_t maxIterations = 1000, double maxDif = 1e-13) {
      size_t it;
      double sum = 0;
      double norm = Norm(vecB);        // Норма
      double dif = norm;               // Невязка, делаем её по умолчанию равной norm, чтобы зашло в цикл
      size_t n = size();
      size_t wide = this->wide();
      size_t halfWide = wide / 2;

      // Итерационный цикл
      for (it = 1; (it <= maxIterations) && (dif > maxDif); it++)
      {
         dif = 0;
         // Пробегаемся по всем строкам матрицы А
         for (size_t i = 0; i < n; i++)
         {
            sum = 0;
            int64_t indX;
            // Пробегаемся по всем столбцам матрицы А
            for (size_t j = 0; j < halfWide; j++)
            {
               indX = i + diagsShift[j];
               if (indX < n)
               {
                  sum += vecX[indX] * diags[j][i];
               }
            }
            sum += vecX[i] * diags[halfWide][i];
            for (size_t j = halfWide + 1; j < wide; j++)
            {
               indX = i + diagsShift[j];
               if (indX >= 0)
               {
                  sum += vecX[indX] * diags[j][i];
               }
            }
            vecX[i] = vecX[i] + (vecB[i] - sum) * relaxCoef / diags[halfWide][i];
            dif += (vecB[i] - sum) * (vecB[i] - sum);          // В данный момент sum = скалярное произведение i-ой строки А на вектор Х
         }

         dif = sqrt(dif) / norm;                               // относительная невязка

         // Выводим на то же место, что и раньше (со сдвигом каретки)
#ifndef NDEBUG
         cout << format("\rИтерация: {0:<10} относительная невязка: {1:<15.3e}", it, dif);
#endif
         if (isinf(dif))
         {
            break;
         }
      }
#ifndef NDEBUG
      cout << endl;
      if (isinf(dif))
      {
         cout << "Выход по переполнению метода" << endl << endl;
      }
      else if (it > maxIterations)
      {
         cout << "Выход по числу итераций" << endl << endl;
      }
      else
      {
         cout << "Выход по относительной невязке" << endl << endl;
      }
#endif

      oDif = dif;
      return it - 1;
   }
};

enum class NodeType {
   undefined,
   normal,
   firstBoundary,
   secondBounary,
   fictive,
};

class GridNode {
public:

   double coordX = 0.0;
   double coordY = 0.0;

   GridNode* leftNode = nullptr;
   GridNode* rightNode = nullptr;
   GridNode* topNode = nullptr;
   GridNode* bottomNode = nullptr;

   NodeType type = NodeType::undefined;
   int numOfBoundaryRegion = 0;        // Не используется, если type != firstBoundary || secondBoundary

   GridNode(double coordX = 0.0, double coordY = 0.0) : coordX{ coordX }, coordY{ coordY } {}
};


struct GridRange {
   double to = 0.0;
   double firstStep = 0.0;
   double stepMultiplier = 1.0;

   GridRange(double to, double firstStep, double stepMult = 1.0) :
      to(to), firstStep(firstStep), stepMultiplier(stepMult) {}

   bool isMultiplied() const { return stepMultiplier == 1.0; };
};


struct GridMaskElement {
   bool isFictive = false;
   bool hasBoundary = false;

   size_t xBeginInd = 0;
   size_t xEndInd = 0;
   size_t yBeginInd = 0;
   size_t yEndInd = 0;
};

vector<GridNode> GenerateGrid() {
   vector<GridNode> grid;

   double xFrom;
   double yFrom;

   vector<GridRange> xRangesComp;
   vector<GridRange> yRangesComp;

   vector<GridMaskElement> gridMask;

   // Допустим, ввод данных скомпрессированной сетки
   xFrom = 0.0;
   yFrom = 0.0;
   xRangesComp.push_back(GridRange(3.0, 1.0));
   xRangesComp.push_back(GridRange(6.0, 1.0));
   xRangesComp.push_back(GridRange(9.0, 0.5));

   yRangesComp.push_back(GridRange(3.0, 0.5));
   yRangesComp.push_back(GridRange(5.0, 1.0));


   // Считываем маску сетки
   auto gridMaskElem = GridMaskElement();
   gridMaskElem.isFictive = true;
   gridMask.push_back(gridMaskElem);

   gridMaskElem = GridMaskElement();
   gridMaskElem.hasBoundary = true;
   //gridMaskElem.bottomBoundary = make_shared<BoundaryParams>(BoundaryType::first, 0);
   gridMask.push_back(gridMaskElem);

   gridMaskElem = GridMaskElement();
   gridMaskElem.isFictive = true;
   gridMask.push_back(gridMaskElem);

   gridMaskElem = GridMaskElement();
   gridMaskElem.hasBoundary = true;
   //gridMaskElem.leftBoundary = make_shared<BoundaryParams>(BoundaryType::first, 0);
   gridMask.push_back(gridMaskElem);

   gridMaskElem = GridMaskElement();
   gridMaskElem.hasBoundary = true;
   //gridMaskElem.topBoundary = make_shared<BoundaryParams>(BoundaryType::first, 0);
   gridMask.push_back(gridMaskElem);

   gridMaskElem = GridMaskElement();
   gridMaskElem.hasBoundary = true;
   //gridMaskElem.rightBoundary = make_shared<BoundaryParams>(BoundaryType::first, 0);
   gridMask.push_back(gridMaskElem);


   // Декомпрессируем сетку, записываем индексы границ каждой сетки, заодно проверяем на то, чтобы она совпадала по шагам с границами
   vector<double> xRanges = { xFrom };
   vector<double> yRanges = { yFrom };
   // Сначала по иксам
   auto prevValue = xFrom;
   for (size_t i = 0; i < xRangesComp.size(); i++) {
      const auto& range = xRangesComp.at(i);
      size_t indBegin = xRanges.size() - 1;
      // Находим крайнее значение, которое на следующем шаге станет близко к [range.to], либо которое превысит [range.to]
      auto currentStep = range.firstStep;
      while (prevValue < range.to && !isAlmostEq(prevValue + currentStep, range.to)) {
         prevValue += currentStep;
         currentStep *= range.stepMultiplier;

         xRanges.push_back(prevValue);
      }
      // Если значение + шаг не близко к range.to, то сетка не совпадает
      if (!isAlmostEq(prevValue + currentStep, range.to)) {
         throw runtime_error(
            format("Диапазон по оси Х [to:{},step:{},mult:{}] не попадает по шагу в конец диапазона.", range.to, range.firstStep, range.stepMultiplier)
         );
      }

      // В конце присваиваем конец сетки для исключения погрешностей
      prevValue = range.to;
      xRanges.push_back(prevValue);

      size_t indEnd = xRanges.size();
      for (size_t j = i; j < gridMask.size(); j += xRangesComp.size()) {
         gridMask.at(j).xBeginInd = indBegin;
         gridMask.at(j).xEndInd = indEnd;
      }
   }
   // Затем по игрекам
   prevValue = yFrom;
   for (size_t i = 0; i < yRangesComp.size(); i++) {
      const auto& range = yRangesComp.at(i);
      size_t indBegin = yRanges.size() - 1;

      auto currentStep = range.firstStep;
      while (prevValue < range.to && !isAlmostEq(prevValue + currentStep, range.to)) {
         prevValue += currentStep;
         currentStep *= range.stepMultiplier;

         yRanges.push_back(prevValue);
      }
      if (!isAlmostEq(prevValue + currentStep, range.to)) {
         throw runtime_error(
            format("Диапазон по оси Y [to:{},step:{},mult:{}] не попадает по шагу в конец диапазона.", range.to, range.firstStep, range.stepMultiplier)
         );
      }
      prevValue = range.to;
      yRanges.push_back(prevValue);

      size_t indEnd = yRanges.size();
      for (size_t j = 0; j < xRangesComp.size(); j++) {
         gridMask.at(i * xRangesComp.size() + j).yBeginInd = indBegin;
         gridMask.at(i * xRangesComp.size() + j).yEndInd = indEnd;
      }
   }

   auto xStepsCount = xRanges.size();
   auto yStepsCount = yRanges.size();

   grid.resize(xStepsCount * yStepsCount);

   for (const auto& gridMaskElem : gridMask) {
      for (size_t i = gridMaskElem.yBeginInd; i < gridMaskElem.yEndInd; i++) {
         for (size_t j = gridMaskElem.xBeginInd; j < gridMaskElem.xEndInd; j++) {
            auto& node = grid.at(i * xStepsCount + j);
            if (node.type == NodeType::undefined) {
               node.coordX = xRanges.at(j);
               node.coordY = yRanges.at(i);
               if (j > 0) {
                  node.leftNode = &(grid.at(i * xStepsCount + j - 1));
               }
               if (j + 1 < xStepsCount) {
                  node.rightNode = &(grid.at(i * xStepsCount + j + 1));
               }
               if (i > 0) {
                  node.bottomNode = &(grid.at((i - 1) * xStepsCount + j));
               }
               if (i + 1 < yStepsCount) {
                  node.topNode = &(grid.at((i + 1) * xStepsCount + j));
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


#ifdef NONE
   // Первых проход - генерируем сетку в виде линейного массива элементов узлов
   auto lastCoordY = yFrom;
   size_t iInGrid = 0;
   // Цикл по игрекам
   for (size_t i = 0; i < yRanges.size(); i++) {
      const auto& yRange = yRanges.at(i);
      auto yStep = yRange.firstStep;

      while (!isAlmostEq(lastCoordY, yRange.to)) {
         // Цикл по искам
         auto lastCoordX = xFrom;
         size_t jInGrid = 0;
         for (size_t j = 0; j < xRanges.size(); j++) {
            const auto& xRange = xRanges.at(j);
            auto xStep = xRange.firstStep;

            //// Если уже прошли первый отрезок, то, 
            //// чтобы избежать дублирования одного и того же узла, пропускаем его
            //if (j > 0) {
            //   lastCoordX += xStep;
            //   xStep *= xRange.stepMultiplier;
            //}
            while (!isAlmostEq(lastCoordX, xRange.to)) {
               auto& node = grid.at(iInGrid * xStepsCount + jInGrid);
               node.coordX = lastCoordX;
               node.coordY = lastCoordY;
               //throw Todo("Проверка типа нода: приоритет: undefined < fictive < normal,bounded");
               //node.type = 

               lastCoordX += xStep;
               xStep *= xRange.stepMultiplier;
            }
            lastCoordX = xRange.to;
         }

         lastCoordY += yStep;
         yStep *= yRange.stepMultiplier;
      }
      lastCoordY = yRange.to;
   }

   // Второй проход - соединяем все узлы-соседи вместе
   for (size_t i = 0; i < yStepsCount; i++) {
      for (size_t j = 0; j < xStepsCount; j++) {
         auto& gridElem = grid.at(i * xStepsCount + j);

         if (j > 0) {
            gridElem.leftNode = &(grid.at(i * xStepsCount + j - 1));
         }
         if (j + 1 < xStepsCount) {
            gridElem.rightNode = &(grid.at(i * xStepsCount + j + 1));
         }
         if (i > 0) {
            gridElem.bottomNode = &(grid.at((i - 1) * xStepsCount + j));
         }
         if (i + 1 < yStepsCount) {
            gridElem.topNode = &(grid.at((i + 1) * xStepsCount + j));
         }
      }
   }
#endif
   cout << "Кхе\n";

   //return grid;
}

int main() {
   setlocale(LC_ALL, "ru-RU");

   GenerateGrid();
   //int size = 0;  // длина диагоналей
   //int space = 0; // отступ между диагоналями
   //vector<int> fiveDiagsShifts = {2 + space, 1, 0, -1, -2 - space};

   //auto mat = DiagonalMatrix();
   //mat.setForm(size, fiveDiagsShifts);

   //// устанавливаем все элементы главной диагонали равными 1
   //for (auto& elem : mat.diags.at(mat.wide() / 2)) {
   //   elem = 1;
   //}
}