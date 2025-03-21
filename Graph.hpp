#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Node.cpp"

namespace graph {

    class Graph {
        int numVertices;
        Node** adjacencyList;
        void removeEdgeHelper(int src, int dest, Node* prev, Node* current);

    public:
        explicit Graph(int vertices);
        ~Graph();
        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph();


    };

}

#endif // GRAPH_HPP
