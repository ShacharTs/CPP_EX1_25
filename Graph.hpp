#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {


    struct Node {
        int dest;
        int weight;
        Node* next;
        Node(const int dest, const int weight, Node* next = nullptr) : dest(dest), weight(weight), next(next) {}
    };

    class Graph {
        int numVertices;
        void removeEdgeHelper(int src, int dest, Node* prev, Node* current);

    private:
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
