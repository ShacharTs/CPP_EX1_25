#include "Algorithms.hpp"
#include "Graph.hpp"

namespace graph {
    bool Algorithms::hasCycle(Graph &g) {
        return true;
    }

    Graph Algorithms::bfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph bfsGraph(size);

        return bfsGraph;
    }

    Graph Algorithms::dfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph dfsGraph(size);

        return dfsGraph;
    }

    Graph Algorithms::dijkstra(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph dijkstraGraph(size);


        return dijkstraGraph;
    }

    Graph Algorithms::prim(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph primGraph(size);


        return primGraph;
    }

    Graph Algorithms::kruskal(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph kruskalGraph(size);


        return kruskalGraph;
    }
}






