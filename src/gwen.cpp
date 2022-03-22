
#include <iostream>
#include <memory>
#include <vector>

#include "Graph.h"

using namespace gwen;

auto ee = std::vector<Graph<size_t>::Edge>{{0, 1}, {0, 1}, {0, 2},
                                           {2, 3}, {1, 4}, {4, 1}};

auto main(int argc, char **argv) -> int {
  std::cout << "this is GWEN" << std::endl;

  auto g = std::make_shared<Graph<size_t>>(ee);
  g->printofant();
}
