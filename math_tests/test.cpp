#include "pch.h"

TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1.0;
   };

   auto funcAt = [](double x, double y) {
      return 5.0;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_xy) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_xx) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * x;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_xxy) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * x * y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * x * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_xyy) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * y * y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * y * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_zero_gamma_is_xxyy) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * x * y * y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * x * y * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}

TEST(tests_where_u_is_five, lambda_is_one_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1.0;
   };

   auto funcAt = [](double x, double y) {
      return 5.0;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_one_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_one_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_one_gamma_is_xy) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_one_gamma_is_xx) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * x;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_one_gamma_is_xxy) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * x * y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * x * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_one_gamma_is_xyy) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x * y * y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x * y * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY))) << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}

TEST(tests_where_u_is_five, lambda_is_x_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_x_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_y_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_five, lambda_is_y_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return 5.0;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return 5.0 * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}



TEST(tests_where_u_is_x, lambda_is_zero_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1;
   };

   auto funcAt = [](double x, double y) {
      return x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_zero_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_zero_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_one_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1;
   };

   auto funcAt = [](double x, double y) {
      return x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_one_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_one_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_x_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1;
   };

   auto funcAt = [](double x, double y) {
      return x - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_x_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_x_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_y_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1;
   };

   auto funcAt = [](double x, double y) {
      return x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_y_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x, lambda_is_y_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}



TEST(tests_where_u_is_y, lambda_is_zero_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1.0;
   };

   auto funcAt = [](double x, double y) {
      return y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_zero_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return y*x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_zero_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return y * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_one_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1.0;
   };

   auto funcAt = [](double x, double y) {
      return y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_one_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return y * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_one_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return y * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_x_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1.0;
   };

   auto funcAt = [](double x, double y) {
      return y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_x_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return y * x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_x_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return y * y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_y_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1.0;
   };

   auto funcAt = [](double x, double y) {
      return y - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_y_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return y*x - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_y, lambda_is_y_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return y * y - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}



TEST(tests_where_u_is_xy, lambda_is_x_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x*y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x*y - y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_xy, lambda_is_x_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x * y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y * y - y;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_xy, lambda_is_y_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x * y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x * x * y - x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_xy, lambda_is_y_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x * y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y * y - x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}



TEST(tests_where_u_is_x_plus_y, lambda_is_x_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x + y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x + x*y - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x_plus_y, lambda_is_x_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x + y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y + y * y - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x_plus_y, lambda_is_y_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x + y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x * x + x * y - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_x_plus_y, lambda_is_y_gamma_is_y) {
   auto firstBoundaryAt = [](double x, double y) {
      return x + y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return y;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 1.0;
   };

   auto gammaAt = [](double x, double y) {
      return y;
   };

   auto funcAt = [](double x, double y) {
      return x * y + y * y - 1;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}



TEST(tests_where_u_is_xx_plus_yy, lambda_is_one_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return x * x + y * y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1;
   };

   auto funcAt = [](double x, double y) {
      return x * x + y * y - 4.0;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_xx_plus_yy, lambda_is_one_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x * x + y * y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x * x + x*y * y - 4.0;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_xx_plus_yy, lambda_is_x_gamma_is_one) {
   auto firstBoundaryAt = [](double x, double y) {
      return x * x + y * y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return 1;
   };

   auto funcAt = [](double x, double y) {
      return x * x + y * y - 6.0*x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}
TEST(tests_where_u_is_xx_plus_yy, lambda_is_x_gamma_is_x) {
   auto firstBoundaryAt = [](double x, double y) {
      return x*x + y*y;
   };

   auto secondBoundaryAt = [](double x, double y) {
      return 0.0;
   };

   auto lambdaAt = [](double x, double y) {
      return x;
   };

   auto lambdaDifxAt = [](double x, double y) {
      return 1.0;
   };

   auto lambdaDifyAt = [](double x, double y) {
      return 0.0;
   };

   auto gammaAt = [](double x, double y) {
      return x;
   };

   auto funcAt = [](double x, double y) {
      return x*x*x + x*y*y - 6*x;
   };

   auto grid = Grid::GenerateGrid();
   auto solver = FDMsolver(grid, firstBoundaryAt, secondBoundaryAt, lambdaAt, lambdaDifxAt, lambdaDifyAt, gammaAt, funcAt);

   auto res = solver.solve();

   for (std::size_t i = 0; i < grid.size(); i++) {
      auto& node = grid.data.at(i);
      if (node.type != Grid::NodeType::fictive) {
         EXPECT_TRUE(isAlmostEq(res.at(i), firstBoundaryAt(node.coordX, node.coordY)))
            << std::format("Expected: {:20.15e}, actual: {:20.15e}", firstBoundaryAt(node.coordX, node.coordY), res.at(i));
      }
   }
}