#include "FDMsolver.h"
#include <exception>

std::vector<double> FDMsolver::solve() {
   using NodeType = Grid::NodeType;

   std::vector<double> ans(grid.size());
   
   // Задаём форму матрицы
   auto size = grid.size();                    // длина диагоналей
   int space = static_cast<int>(grid.sizeX);   // отступ между диагоналями
   std::vector<int> fiveDiagsShifts = { -space, -1, 0, 1, space };

   // Создаём матрицу заданной формы
   auto mat = DiagonalMatrix();
   mat.setForm(size, fiveDiagsShifts);

   // устанавливаем все элементы главной диагонали равными 1
   for (auto& elem : mat.getMainDiag()) { elem = 1; }

   // Вектор правой части
   auto rightVec = std::vector<double>(size);

   // Заполняем матрицу и вектор правой части значениями
   for (std::size_t i = 0; i < grid.sizeY; i++) {
      for (std::size_t j = 0; j < grid.sizeX; j++) {
         auto linearPos = i * grid.sizeX + j;
         const auto& nodeElem = grid.data.at(linearPos);

         switch (nodeElem.type)
         {
         case NodeType::fictive:
            rightVec.at(linearPos) = 0;
            break;

         case NodeType::firstBoundary:
            rightVec.at(linearPos) = firstBoundaryAt(nodeElem.boundaryRegionNum, nodeElem.coordX, nodeElem.coordY);
            break;

         case NodeType::secondBounary: {
            const double lambda = lambdaAt(nodeElem.coordX, nodeElem.coordY);
            auto& diags = mat.diags;
            double h;

            // Если краевое задано вдоль оси X
            if (nodeElem.isBoundaryAlongX) {
               if (nodeElem.bottomNode == nullptr && nodeElem.topNode == nullptr) {
                  throw std::runtime_error("Неверно задано второе краевое условие: ни сверху, ни снизу по грани нет узлов");
               }
               // Если краевое задано по нижней границе
               if ((nodeElem.bottomNode == nullptr || nodeElem.bottomNode->type == NodeType::fictive) &&
                  nodeElem.topNode != nullptr) {
                  h = (nodeElem.topNode->coordY - nodeElem.coordY);

                  diags[2].at(linearPos) = lambda / h;
                  diags[4].at(linearPos) = -lambda / h;
               }
               // Если задано по верхней границе и снизу не фиктивные узлы
               else if (nodeElem.bottomNode != nullptr && nodeElem.bottomNode->type != NodeType::fictive){
                  h = (nodeElem.coordY - nodeElem.bottomNode->coordY);

                  diags[2].at(linearPos) = lambda / h;
                  diags[0].at(linearPos) = -lambda / h;
               }
               else {
                  throw std::runtime_error("Неверно задано второе краевое условие: ни сверху, ни снизу по грани нет узлов");
               }
            }
            // Если вдоль оси Y
            else {
               if (nodeElem.leftNode == nullptr && nodeElem.rightNode == nullptr) {
                  throw std::runtime_error("Неверно задано второе краевое условие: ни сверху, ни снизу по грани нет узлов");
               }
               // Если краевое задано по нижней границе
               if ((nodeElem.leftNode == nullptr || nodeElem.leftNode->type == NodeType::fictive) &&
                  nodeElem.rightNode != nullptr) {
                  h = (nodeElem.rightNode->coordX - nodeElem.coordX);

                  diags[2].at(linearPos) = lambda / h;
                  diags[3].at(linearPos) = -lambda / h;
               }
               // Если задано по верхней границе и снизу не фиктивные узлы
               else if (nodeElem.leftNode != nullptr && nodeElem.leftNode->type != NodeType::fictive) {
                  h = (nodeElem.coordX - nodeElem.leftNode->coordX);

                  diags[1].at(linearPos) = -lambda / h;
                  diags[2].at(linearPos) = lambda / h;
               }
               else {
                  throw std::runtime_error("Неверно задано второе краевое условие: ни сверху, ни снизу по грани нет узлов");
               }
            }

            rightVec.at(linearPos) = secondBoundaryAt(nodeElem.boundaryRegionNum, nodeElem.coordX, nodeElem.coordY);

            break;
         }

         case NodeType::thirdBoundary: {
            const double lambda = lambdaAt(nodeElem.coordX, nodeElem.coordY);
            auto& diags = mat.diags;
            double h;
            double beta = thirdBoundaryBetaAt(nodeElem.boundaryRegionNum, nodeElem.coordX, nodeElem.coordY);

            // Если краевое задано вдоль оси X
            if (nodeElem.isBoundaryAlongX) {
               // Проверка на правильность задания краевых условий
               if (nodeElem.bottomNode == nullptr && nodeElem.topNode == nullptr) {
                  throw std::runtime_error("Неверно задано третье краевое условие: ни сверху, ни снизу по грани нет узлов");
               }
               // Если краевое задано сверху
               if ((nodeElem.topNode == nullptr || nodeElem.topNode->type == NodeType::fictive) &&
                  nodeElem.bottomNode != nullptr) {
                  h = (nodeElem.coordY - nodeElem.bottomNode->coordY);

                  diags[0].at(linearPos) = -lambda / h;
                  diags[2].at(linearPos) = lambda / h + beta;
               }
               // Если краевое задано снизу
               else if (nodeElem.topNode != nullptr && nodeElem.topNode->type != NodeType::fictive) {
                  h = (nodeElem.topNode->coordY - nodeElem.coordY);

                  diags[2].at(linearPos) = lambda / h + beta;
                  diags[4].at(linearPos) = -lambda / h;
               }
               else {
                  throw std::runtime_error("Неверно задано третье краевое условие: ни сверху, ни снизу по грани нет узлов");
               }
            }
            // Если вдоль оси Y
            else {
               // Проверка на правильность задания краевых условий
               if (nodeElem.leftNode == nullptr && nodeElem.rightNode == nullptr) {
                  throw std::runtime_error("Неверно задано третье краевое условие: ни слева, ни справа по грани нет узлов");
               }
               // Если краевое задано справа
               if ((nodeElem.rightNode == nullptr || nodeElem.rightNode->type == NodeType::fictive) &&
                  nodeElem.leftNode != nullptr) {
                  h = (nodeElem.coordX - nodeElem.leftNode->coordX);

                  diags[1].at(linearPos) = -lambda / h;
                  diags[2].at(linearPos) = lambda / h + beta;
               }
               // Если краевое задано слева
               else if (nodeElem.rightNode != nullptr && nodeElem.rightNode->type != NodeType::fictive) {
                  h = (nodeElem.rightNode->coordX - nodeElem.coordX);

                  diags[2].at(linearPos) = lambda / h + beta;
                  diags[3].at(linearPos) = -lambda / h;
               }
               else {
                  throw std::runtime_error("Неверно задано третье краевое условие: ни слева, ни справа по грани нет узлов");
               }
            }

            rightVec.at(linearPos) = beta * thirdBoundaryAt(nodeElem.boundaryRegionNum, nodeElem.coordX, nodeElem.coordY);

            break;
         }
         
         case NodeType::normal: {
            const double doubledLambda = 2.0 * lambdaAt(nodeElem.coordX, nodeElem.coordY);
            const double lambdaDifx = lambdaDifxAt(nodeElem.coordX, nodeElem.coordY);
            const double lambdaDify = lambdaDifyAt(nodeElem.coordX, nodeElem.coordY);

            std::array<double, 2> h_x = {
                nodeElem.coordX - nodeElem.leftNode->coordX,
                nodeElem.rightNode->coordX - nodeElem.coordX,
            };
            std::array<double, 2> h_y = {
                nodeElem.coordY - nodeElem.bottomNode->coordY,
                nodeElem.topNode->coordY - nodeElem.coordY,
            };

            auto& diags = mat.diags;

            // Нижний элемент
            diags[0].at(linearPos) = -((doubledLambda / (h_y[0] * (h_y[1] + h_y[0]))) - lambdaDify / (h_y[0] + h_y[1]));

            diags[1].at(linearPos) = -((doubledLambda / (h_x[0] * (h_x[1] + h_x[0]))) - lambdaDifx / (h_x[0] + h_x[1]));

            // центральный элемент
            diags[2].at(linearPos) = (doubledLambda / (h_x[0] * h_x[1]) + doubledLambda / (h_y[0] * h_y[1])) +
               gammaAt(nodeElem.coordX, nodeElem.coordY);

            diags[3].at(linearPos) = -((doubledLambda / (h_x[1] * (h_x[1] + h_x[0]))) + lambdaDifx / (h_x[0] + h_x[1]));

            diags[4].at(linearPos) = -((doubledLambda / (h_y[1] * (h_y[1] + h_y[0]))) + lambdaDify / (h_y[0] + h_y[1]));

            // Значение функции
            rightVec.at(linearPos) = funcAt(nodeElem.coordX, nodeElem.coordY);

            break;
         }
         default:
            throw std::runtime_error(
               std::format("Что-то пошло не так: неинициализированный или нереализованный узел под индексом {}", linearPos)
            );
            break;
         }
      }
   }

   // Решаем СЛАУ
   double dif = 0.0;
   mat.seidelSolve(rightVec, ans, dif, 1.0, 10000, 2e-15);

   return ans;
}
