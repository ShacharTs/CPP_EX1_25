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
        auto visited = new bool[size] {false};
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

    void dfsRec(Graph &g,bool visited[], int source,int size) {
        visited[source] = true;
        cout << "Starting DFS from node: " << source << endl;
        for (int i = 0; i < size; i++) {
            if (visited[i] == false) {
                dfsRec(g,visited,i,size);
            }
        }
    }

    void Algorithms::dfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        bool* visited = new bool[size] {false};
        dfsRec(g,visited,source,size);

        delete[] visited;
    }



    void Algorithms::dijkstra(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph dijkstraGraph(size);



    }

    void Algorithms::prim(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph primGraph(size);



    }

    void Algorithms::kruskal(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        Graph kruskalGraph(size);



    }
}






