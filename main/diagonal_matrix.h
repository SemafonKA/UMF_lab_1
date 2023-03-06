#pragma once
#include <vector>
#include <stdexcept>
#include <format>
#include <iostream>

double Norm(const std::vector<double>& X);

class DiagonalMatrix {
public:
   std::vector<std::vector<double>> diags;

   std::vector<int> diagsShift;

   void setForm(std::size_t size, std::vector<int> shifts);

   std::size_t size() {
      if (diags.empty()) {
#ifndef NDEBUG
         throw std::runtime_error("Matrix is not formed!");
#else 
         return 0;
#endif
      }
      return diags.at(0).size();
   }

   std::size_t wide() {
      return diags.size();
   }

   std::vector<double>& getMainDiag() {
      size_t mainDiagPos = wide() / 2;
      return diags.at(mainDiagPos);
   }

   std::size_t seidelSolve(const std::vector<double>& vecB, std::vector<double>& vecX, double& outDif, double relaxCoef = 0.5,
      std::size_t maxIterations = 1000, double maxDif = 1e-13);
};