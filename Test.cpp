#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Example")
{
    graph::Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.print_graph();
    graph::Algorithms::bfs(g,2);


}