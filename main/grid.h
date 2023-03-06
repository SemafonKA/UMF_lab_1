#pragma once
#include <vector>

namespace Grid {
   /// <summary>
   /// Type of node of grid
   /// </summary>
   enum class NodeType {
      undefined,
      normal,
      firstBoundary,
      secondBounary,
      fictive,
   };

   /// <summary>
   /// Single element of grid, that contains his type, pointers to his neighbors and coordinates
   /// </summary>
   class GridNode {
   public:

      double coordX = 0.0;
      double coordY = 0.0;

      GridNode* leftNode = nullptr;
      GridNode* rightNode = nullptr;
      GridNode* topNode = nullptr;
      GridNode* bottomNode = nullptr;

      NodeType type = NodeType::undefined;

      /// <summary>
      /// Default constructor of grid element
      /// </summary>
      /// <param name="coordX"> - coordinate of node by X</param>
      /// <param name="coordY"> - coordinate of node by Y</param>
      GridNode(double coordX = 0.0, double coordY = 0.0) : coordX{ coordX }, coordY{ coordY } {}
   };

   class Grid {
   public:
      std::vector<GridNode> data;

      std::size_t size() {
         return data.size();
      }

      std::size_t sizeX = 0;
      std::size_t sizeY = 0;
   };
}