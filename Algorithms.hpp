
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"


namespace graph {
    class Algorithms {
    public:
       static  bool hasCycle(Graph& g);
        Graph bfs(Graph& g, int source);
        Graph dfs(Graph& g, int source);
        Graph dijkstra (Graph& g, int source);
        Graph prim (Graph& g, int source);
        Graph kruskal(Graph& g, int source);
    };

}


#endif //ALGORITHMS_HPP
