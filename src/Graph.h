#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

namespace gwen {
template <typename VertexId> struct Graph {
  struct Edge {
    VertexId from;
    VertexId to;

    auto stringofant() -> std::string {
      return fmt::format("{} --> {}", from, to);
    }
  };

  struct Vertex {
    std::vector<std::shared_ptr<Edge>> in;
    std::vector<std::shared_ptr<Edge>> out;
  };

  Graph(std::vector<Edge> someEdges) {
    for (auto const &e : someEdges) {
      auto id = edges.emplace_back(std::make_shared<Edge>(e));
      vertices[id->from].out.emplace_back(id);
      vertices[id->to].in.emplace_back(id);
    }
  }

  auto printofant() -> void {
    std::cout << "Hi, I am a GWEN" << std::endl;
    std::cout << " my vertices are: ";
    for (auto const [vid, vert] : vertices) {
      std::cout << vid << ", ";
      std::cout << "in-edges:  ";
      for (auto const e : vert.in) {
        std::cout << e->stringofant() << ", ";
      }
      std::cout << ", out-edges: ";
      for (auto const e : vert.out) {
        std::cout << e->stringofant() << ", ";
      }
      std::cout << std::endl;
    }
  }

  std::vector<std::shared_ptr<Edge>> edges;
  std::unordered_map<VertexId, Vertex> vertices;
};
} // namespace gwen
