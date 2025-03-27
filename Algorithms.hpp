#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"


namespace graph {
    class Algorithms {
    public:
        static int* bfs(Graph& g, int source);
        Graph static dfs(Graph& g, int source);
        Graph static dijkstra (Graph& g, int source);
        Graph static prim (Graph& g);
        Graph static kruskal(Graph& g);
    };

}


#endif //ALGORITHMS_HPP
