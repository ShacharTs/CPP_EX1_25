#include "Algorithms.hpp"
#include "Graph.hpp"
#include "Queue.cpp"
#include <iostream>

using namespace  std;

namespace graph {
    bool Algorithms::hasCycle(Graph &g) {
        return true;
    }

    void Algorithms::bfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        const auto visited = new bool[size] {false};
        Queue q(size);

        visited[source] = true;
        q.enqueue(source);
        cout << "Starting BFS from node: " << source << endl;

        while (!q.isEmpty()) {
            const int current = q.getFront();
            q.dequeue();
            cout << "Visited Node: " << current << endl;
            const Node* currentNode = g.adjacencyList[current];
            while (currentNode != nullptr) {
                if (!visited[currentNode->dest]) {
                    visited[currentNode->dest] = true;
                    q.enqueue(currentNode->dest);
                }
                currentNode = currentNode->next;
            }
        }
        delete[] visited;
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






