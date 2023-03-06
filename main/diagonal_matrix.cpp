#include "diagonal_matrix.h"

double Norm(const std::vector<double>& X)
{
    double norma = 0;
    for (std::size_t i = 0; i < X.size(); i++)
    {
        norma += X[i] * X[i];
    }
    norma = std::sqrt(norma);
    return norma;
}

void DiagonalMatrix::setForm(std::size_t size, std::vector<int> shifts) {
    if ((shifts.size() & 1) != 1) {
        throw std::runtime_error("Number of diagonals must be the odd");
    }

    diagsShift = std::move(shifts);

    diags.resize(diagsShift.size());
    for (auto& diag : diags) {
        diag.resize(size);
    }
}

std::size_t DiagonalMatrix::seidelSolve(const std::vector<double>& vecB, std::vector<double>& vecX, double& outDif, 
   double relaxCoef, std::size_t maxIterations, double maxDif) {
    std::size_t it;
    double sum = 0;
    double norm = Norm(vecB);        // Норма
    double dif = norm;               // Невязка, делаем её по умолчанию равной norm, чтобы зашло в цикл
    std::size_t n = size();
    std::size_t wide = this->wide();
    std::size_t halfWide = wide / 2;

    // Итерационный цикл
    for (it = 1; (it <= maxIterations) && (dif > maxDif); it++)
    {
        dif = 0;
        // Пробегаемся по всем строкам матрицы А
        for (std::size_t i = 0; i < n; i++)
        {
            sum = 0;
            // Пробегаемся по всем столбцам матрицы А
            for (std::size_t j = 0; j < halfWide; j++)
            {
                std::int64_t indX = i + diagsShift[j];
                if (indX >= 0)
                {
                    sum += vecX[indX] * diags[j][i];
                }
            }
            sum += vecX[i] * diags[halfWide][i];
            for (std::size_t j = halfWide + 1; j < wide; j++)
            {
                std::uint64_t indX = i + diagsShift[j];
                if (indX < n)
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
        std::cout << std::format("\rИтерация: {0:<10} относительная невязка: {1:<15.3e}", it, dif);
#endif
        if (isinf(dif))
        {
            break;
        }
    }
#ifndef NDEBUG
    std::cout << std::endl;
    if (std::isinf(dif))
    {
        std::cout << "Выход по переполнению метода" << std::endl << std::endl;
    }
    else if (it > maxIterations)
    {
        std::cout << "Выход по числу итераций" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Выход по относительной невязке" << std::endl << std::endl;
    }
#endif

    outDif = dif;
    return it - 1;
}
