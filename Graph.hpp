#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Node.hpp"
namespace graph {


    class Graph {
        int numVertices;
        void removeEdgeHelper(int src, int dest, Node* prev, Node* current);

        void dfsRec(Graph &g,bool visited[], int source);

    public:
        Node** adjacencyList;
        explicit Graph(int vertices);
        ~Graph();
        void addEdge(int src, int dest, int weight = 1);

        void addEdgeForBFSTree(int src, int dest, int weight);

        void removeEdge(int src, int dest);
        void print_graph();
        int getNumberOfVertices();

    };

}

#endif // GRAPH_HPP
