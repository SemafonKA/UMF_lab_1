#include "FDMsolver.h"

std::vector<double> FDMsolver::solve() {
    using NodeType = Grid::NodeType;

    std::vector<double> ans(grid.size());

    // ����� ����� �������
    auto size = grid.size();                    // ����� ����������
    int space = static_cast<int>(grid.sizeX);   // ������ ����� �����������
    std::vector<int> fiveDiagsShifts = { -space, -1, 0, 1, space };

    // ������ ������� �������� �����
    auto mat = DiagonalMatrix();
    mat.setForm(size, fiveDiagsShifts);

    // ������������� ��� �������� ������� ��������� ������� 1
    for (auto& elem : mat.getMainDiag()) { elem = 1; }

    // ������ ������ �����
    auto rightVec = std::vector<double>(size);

    // ��������� ������� � ������ ������ ����� ����������
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
                rightVec.at(linearPos) = firstBoundaryAt(nodeElem.coordX, nodeElem.coordY);
                break;

            case NodeType::secondBounary:
                rightVec.at(linearPos) = secondBoundaryAt(nodeElem.coordX, nodeElem.coordY);
                break;

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

                // ������ �������
                diags[0].at(linearPos) = -((doubledLambda / (h_y[0] * (h_y[1] + h_y[0]))) - lambdaDify / (h_y[0] + h_y[1]));

                // ����� �������
                diags[1].at(linearPos) = -((doubledLambda / (h_x[0] * (h_x[1] + h_x[0]))) - lambdaDifx / (h_x[0] + h_x[1]));

                // ����������� �������
                diags[2].at(linearPos) = (doubledLambda / (h_x[0] * h_x[1]) + doubledLambda / (h_y[0] * h_y[1])) +
                    gammaAt(nodeElem.coordX, nodeElem.coordY);

                // ������ �������
                diags[3].at(linearPos) = -((doubledLambda / (h_x[1] * (h_x[1] + h_x[0]))) + lambdaDifx / (h_x[0] + h_x[1]));

                // ������� �������
                diags[4].at(linearPos) = -((doubledLambda / (h_y[1] * (h_y[1] + h_y[0]))) + lambdaDify / (h_y[0] + h_y[1]));

                // �������� �������
                rightVec.at(linearPos) = funcAt(nodeElem.coordX, nodeElem.coordY);

                break;
            }
            default:
                throw std::runtime_error(
                    std::format("���-�� ����� �� ���: �������������������� ��� ��������������� ���� ��� �������� {}", linearPos)
                );
                break;
            }
        }
    }

    // ������ ����
    double dif = 0.0;
    mat.seidelSolve(rightVec, ans, dif, 1.0, 10000, 1e-15);

    return ans;
}
