#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Test BFS on Graph") {
    graph::Graph g(5);

    // Add edges
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    // Print the graph (optional, for visual confirmation)
    cout << "Graph after adding edges:" << endl;
    g.print_graph();

    // Call BFS from node 4
    cout << "\nRunning BFS starting from node 4:" << endl;
    graph::Algorithms::bfs(g, 4);

}

TEST_CASE("Test DFS on Graph") {
    graph::Graph g(5);

    // Add edges
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    cout << "\nRunning DFS starting from node 4:" << endl;
    graph::Algorithms::dfs(g, 4);

}

TEST_CASE("Test graph edge removal") {
    graph::Graph g(5);

    // Add edges
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    // Remove an edge and check the result
    g.removeEdge(1, 4);
    cout << "Graph after removing edge (1, 4):" << endl;
    g.print_graph();

    g.removeEdge(0, 1);
    cout << "Graph after removing edge (0, 1):" << endl;
    g.print_graph();

    g.removeEdge(3, 4);
    cout << "Graph after removing edge (3, 4):" << endl;
    g.print_graph();
}

