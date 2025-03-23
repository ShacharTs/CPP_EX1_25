#include "Algorithms.hpp"
#include "Graph.hpp"
#include "Queue.cpp"
#include "PQueue.cpp"
#include <iostream>

using namespace  std;

namespace graph {

    void resetVisit(bool* visited,int graphSize) {
        for (int i = 0; i < graphSize; i++) {
            visited[i] = false;
        }
    }

    void resetDist(int* dist,int graphSize) {
        for (int i = 0; i < graphSize; i++) {
            dist[i] = INT_MAX;
        }
    }

    /**
     * Bfs method to look for all the nodes
     * @param g Graph
     * @param source Node
     */
    void Algorithms::bfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        bool* visited = new bool[size];
        resetVisit(visited,size);

        Queue q(size);

        visited[source] = true;
        q.enqueue(source);
        cout << "Starting BFS from node: " << source << endl;
        /*
         * This loop runs as long as the queue is not empty.
         * It processes each node by dequeue it, marking it as visited, and exploring its neighbors.
         * If a neighbor has not been visited, it is enqueued to explore its neighbors in the next iterations.
         */
        while (!q.isEmpty()) {
            const int current = q.getFront();
            q.dequeue();
            cout << "Visited Node: " << current << endl;
            const Node* currentNode = g.adjacencyList[current];
            while (currentNode != nullptr) { // check if the current node has neighbors to explore
                if (!visited[currentNode->dest]) {
                    visited[currentNode->dest] = true; // mark neighbors as visited
                    q.enqueue(currentNode->dest); // enqueue unvisited neighbors
                }
                currentNode = currentNode->next; // move to the next child
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
        bool* visited = new bool[size];

        resetVisit(visited,size);

        dfsRec(g,visited,source,size);
        delete[] visited;
    }


    /**
     *
     * @param dist dist from one node
     * @param visited
     * @param distSize
     * @return
     */
    int minDist(const int* dist, const bool* visited, const int distSize) {
        int min = INT_MAX;
        int idx = -1;
        for (int i = 0; i< distSize; i++) {
            if (!visited[i] && dist[i] <min) {
                min = dist[i];
                idx = i;
            }
        }
        return idx;
    }

    /**
     * Dijkstra, check for the shortest path in graph when node got weight
     * @param g Graph
     * @param source Node
     */
    void Algorithms::dijkstra(Graph &g, const int source) {
        const int size = g.getNumberOfVertices();
        int* dist = new int [size]; // array of the shortest path

        resetDist(dist,size);

        bool* visited = new bool[size];
        resetVisit(visited,size);

        PQueue pq (size); // add graph size to PQ
        dist[source] = 0; // starting point

        for (int i = 0; i < size; i++) {
            const int temp = minDist(dist,visited,size);
            if (temp == -1) { // if dist is negative, dijkstra will fail
                cout << "Found negative dist, dijkstra will fail" << endl;
                break;
            }
            visited[temp] = true;
             Node* current =g.adjacencyList[temp];
            while (current!=nullptr) {
                const int neighbor = current->dest; // neighbor node
                const int weight = current->weight; // neighbor weight
                // checks few conditions
                // 1) if node already visited
                // 2) checks if (the current dist path plus new weight) is less than a neighbor total path
                if (!visited[neighbor] && dist[temp] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[temp] + weight; // add the new weight to the dist
                    pq.enqueue(neighbor,dist[neighbor]);
                }
                current = current->next; // go to the next node
            }
        }
        cout << "Shortest distances from source node " << source << endl;
        for (int i = 0; i< size; i++) {
            cout << "Node: " << i << " dist: "<< dist[i] << endl;
        }
        // free memory
        delete[] dist;
        delete[] visited;
    }

    /**
     * 
     * @param g Graph
     * @param source Node
     */
    void Algorithms::prim(Graph &g, int source) {
        const int size = g.getNumberOfVertices();




    }

    /**
     * 
     * @param g Graph
     * @param source Node
     */
    void Algorithms::kruskal(Graph &g, int source) {
        const int size = g.getNumberOfVertices();




    }
}






