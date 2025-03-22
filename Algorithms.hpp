
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"


namespace graph {
    class Algorithms {
    public:
        static bool hasCycle(Graph& g);
        static void bfs(Graph& g, int source);
        static void dfs(Graph& g, int source);
        static void dijkstra (Graph& g, int source);
        static void prim (Graph& g, int source);
        static void kruskal(Graph& g, int source);
    };

}


#endif //ALGORITHMS_HPP
