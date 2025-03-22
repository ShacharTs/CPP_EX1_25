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

    /**
     *  Helper method to use DFS in recursive way (Idea from GFG)
     * @param g graph
     * @param visited array of node visited (Marked True or False)
     * @param source Node source for dfs
     * @param sizeGraph the size of graph (in nodes)
     */
    void dfsRec(Graph &g,bool visited[], int source,int sizeGraph) {
        visited[source] = true;
        cout << "Starting DFS from node: " << source << endl;
        for (int i = 0; i < sizeGraph; i++) {
            if (visited[i] == false) {
                dfsRec(g,visited,i,sizeGraph);
            }
        }
    }

    /**
     * Dfs will call its helper method dfsRec to search for all the nodes
     * @param g Graph
     * @param source Node (Start Node)
     */
    void Algorithms::dfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        bool* visited = new bool[size] {false};
        dfsRec(g,visited,source,size);
        delete[] visited;
    }



    void Algorithms::dijkstra(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        ;



    }

    void Algorithms::prim(Graph &g, int source) {
        const int size = g.getNumberOfVertices();




    }

    void Algorithms::kruskal(Graph &g, int source) {
        const int size = g.getNumberOfVertices();




    }
}






