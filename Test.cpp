#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
#include <iostream>

#include "PQueue.hpp"

using namespace std;

TEST_CASE("Test BFS on Graph") {
    graph::Graph g(8);
    g.addEdge(0,1,10);
    g.addEdge(0,2,1);
    g.addEdge(0,3,4);
    g.addEdge(1,4,0);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(2,5,8);
    g.addEdge(3,5,2);
    g.addEdge(3,6,7);
    g.addEdge(4,5,1);
    g.addEdge(4,7,8);
    g.addEdge(5,7,9);
    g.addEdge(5,6,6);
    g.addEdge(6,7,12);

    graph::Algorithms::bfs(g, 0);
}

TEST_CASE("Test DFS on Graph") {
    graph::Graph g(8);
    g.addEdge(0,1,10);
    g.addEdge(0,2,1);
    g.addEdge(0,3,4);
    g.addEdge(1,4,0);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(2,5,8);
    g.addEdge(3,5,2);
    g.addEdge(3,6,7);
    g.addEdge(4,5,1);
    g.addEdge(4,7,8);
    g.addEdge(5,7,9);
    g.addEdge(5,6,6);
    g.addEdge(6,7,12);

    graph::Algorithms::dfs(g, 0);

}

TEST_CASE("Test Dijkstra on Graph") {
    graph::Graph g(8);
    g.addEdge(0,1,10);
    g.addEdge(0,2,1);
    g.addEdge(0,3,4);
    g.addEdge(1,4,0);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(2,5,8);
    g.addEdge(3,5,2);
    g.addEdge(3,6,7);
    g.addEdge(4,5,1);
    g.addEdge(4,7,8);
    g.addEdge(5,7,9);
    g.addEdge(5,6,6);
    g.addEdge(6,7,12);
    graph::Algorithms::dijkstra(g, 0);

}

TEST_CASE("Test Dijkstra on Graph with negaive") {
    graph::Graph g(8);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,1);
    g.addEdge(0,3,4);
    g.addEdge(1,4,0);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(2,5,8);
    g.addEdge(3,5,2);
    g.addEdge(3,6,7);
    g.addEdge(4,5,1);
    g.addEdge(4,7,8);
    g.addEdge(5,7,9);
    g.addEdge(5,6,6);
    g.addEdge(6,7,12);
    CHECK_THROWS(graph::Algorithms::dijkstra(g, 0));

}


TEST_CASE("Test Prim on Graph") {
    graph::Graph g(8);
    g.addEdge(0,1,10);
    g.addEdge(0,2,1);
    g.addEdge(0,3,4);
    g.addEdge(1,4,0);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(2,5,8);
    g.addEdge(3,5,2);
    g.addEdge(3,6,7);
    g.addEdge(4,5,1);
    g.addEdge(4,7,8);
    g.addEdge(5,7,9);
    g.addEdge(5,6,6);
    g.addEdge(6,7,12);

    graph::Graph h  = graph::Algorithms::prim(g);

}

TEST_CASE("Test Kruskal on Graph") {
    graph::Graph g(8);
    g.addEdge(0,1,10);
    g.addEdge(0,2,1);
    g.addEdge(0,3,4);
    g.addEdge(1,4,0);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(2,5,8);
    g.addEdge(3,5,2);
    g.addEdge(3,6,7);
    g.addEdge(4,5,1);
    g.addEdge(4,7,8);
    g.addEdge(5,7,9);
    g.addEdge(5,6,6);
    g.addEdge(6,7,12);

    graph::Graph h  = graph::Algorithms::kruskal(g);

}

TEST_CASE("Test has cycle") {
    graph::Graph g(8);
    g.addEdge(0,1,10);
    g.addEdge(0,2,1);
    g.addEdge(0,3,4);
    g.addEdge(1,4,0);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(2,5,8);
    g.addEdge(3,5,2);
    g.addEdge(3,6,7);
    g.addEdge(4,5,1);
    g.addEdge(4,7,8);
    g.addEdge(5,7,9);
    g.addEdge(5,6,6);
    g.addEdge(6,7,12);

    graph::Graph h  = graph::Algorithms::kruskal(g);
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

TEST_CASE("PQ Full") {
    PQueue<Node> pq (2);
    pq.enqueue(0,0,0);
    pq.enqueue(1,0,0);
    CHECK_THROWS(pq.enqueue(2,0,0));
}

TEST_CASE("PQ Empty") {
    PQueue<Node> pq (1);
    pq.enqueue(0,0,0);
    pq.dequeue();
    CHECK_THROWS(pq.dequeue());
}

