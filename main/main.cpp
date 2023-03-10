#include <iostream>
#include <vector>
#include <array>
#include <format>
#include <fstream>
#include "diagonal_matrix.h"
#include "grid.h"
#include "grid.generator.h"
#include "functions.h"
#include "FDMsolver.h"

using namespace std;
using NodeType = Grid::NodeType;

int main() {
   setlocale(LC_ALL, "ru-RU.utf8");
   //auto outStream = ofstream("out.txt");
   auto& outStream = cout;

   // Пока что сетка генерируется в фиксированном формате формы Т (либо иной другой, если её захардкодить)
   Grid::Grid grid;
   try {
      grid = Grid::GenerateGrid();
   }
   catch (exception e) {
      cerr << e.what() << endl;
   }
   vector<double> ans;

   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);
   try {
      ans = solver.solve();
   }
   catch (exception e) {
      cerr << e.what() << endl;
   }

   double normDeltaU = 0.0;
   double normU = 0.0;

   outStream << "Полученное решение: \n\n";
   for (size_t i = 0; i < grid.sizeY; i++) {
      for (size_t j = 0; j < grid.sizeX; j++) {
         const auto& node = grid.data.at(i * grid.sizeX + j);
         string type;
         switch (node.type)
         {
         case NodeType::fictive:
            type = "fictive";
            break;

         case NodeType::normal:
            type = "normal";
            break;

         case NodeType::firstBoundary:
            type = "firstBoundary";
            break;

         case NodeType::secondBounary:
            type = "secondBoundary";
            break;

         default:
            type = "none";
            break;
         }
         //auto nodeStr = format("(x:{: 20.14e},y:{: 20.14e}, type:{})", node.coordX, node.coordY, type);
         //outStream << format("Node: {:<70}, value: {: 20.14e}\n", nodeStr, ans.at(i * grid.sizeX + j));

         if (node.type != NodeType::fictive && !isAlmostEq(firstBoundaryAt(node.coordX, node.coordY), 0.0)) {
            auto u = firstBoundaryAt(node.coordX, node.coordY);
            normU = u * u;

            auto deltaU = (ans.at(i * grid.sizeX + j) - firstBoundaryAt(node.coordX, node.coordY));
            normDeltaU += deltaU * deltaU;
         }


#ifndef NDEBUG
         if (node.type != NodeType::fictive && !isAlmostEq(ans.at(i * grid.sizeX + j), firstBoundaryAt(node.coordX, node.coordY))) {
            outStream << format("{:!^106}\n", " Этот узел не похож на верный ответ ");
            outStream << format("{:!^106}\n", format(" Ожидалось: {: 20.15e} ", firstBoundaryAt(node.coordX, node.coordY)));
            outStream << format("{:!^106}\n", format(" Погрешность: {: 20.15e} ", abs(ans.at(i * grid.sizeX + j) - firstBoundaryAt(node.coordX, node.coordY))));
            outStream << format("{:!^106}\n", format(" Относ. погрешность: {: 20.15e} ", (ans.at(i * grid.sizeX + j) - firstBoundaryAt(node.coordX, node.coordY)) / firstBoundaryAt(node.coordX, node.coordY)));
         }
#endif // !NDEBUG
      }
      outStream << endl;
   }

   outStream << format("Норма вектора deltaU равна {: 20.14e}\n", sqrt(normDeltaU));
   outStream << format("Нормированная норма вектора deltaU равна {: 20.14e}\n", sqrt(normDeltaU / normU));
}