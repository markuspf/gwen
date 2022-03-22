#pragma once

#include <memory>

namespace gwen {
template <typename VertexId> struct Graph {
  struct Edge {
    VertexId from;
    VertexId to;
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

  std::vector<std::shared_ptr<Edge>> edges;
  std::vector<std::unordered_map<VertexId, Vertex>> vertices;
}
} // namespace gwen
