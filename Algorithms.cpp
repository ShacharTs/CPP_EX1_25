#include "Algorithms.hpp"
#include "Graph.hpp"
#include "Queue.cpp"
#include "PQueue.cpp"
#include "math.h"
#include <iostream>

using namespace  std;

namespace graph {

    void resetVisit(bool* visited,int graphSize) {
        for (int i = 0; i < graphSize; i++) {
            visited[i] = false;
        }
    }

    void initDistance(int* dist,int graphSize) {
        for (int i = 0; i < graphSize; i++) {
            dist[i] = INFINITY;
        }
    }

    // Helper function to print the path from source to node
    void printPath(int* prev, int node) {
        if (node == -1) {
            return; // Base case: reached the source
        }
        printPath(prev, prev[node]); // Recursively print predecessor path
        cout << node << " "; // Then print current node
    }





    /**
     * Bfs method to look for all the nodes
     * @param g Graph
     * @param source Node
     */
    int* Algorithms::bfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        bool* visited = new bool[size];
        resetVisit(visited, size);

        // Create an array to hold the parent for each vertex.
        // Initially, set all parents to -1.
        int* parent = new int[size];
        for (int i = 0; i < size; ++i) {
            parent[i] = -1;
        }

        PQueue pq(size);
        int order = 0;


        visited[source] = true;
        parent[source] = 0;
        pq.enqueue(source, order++);
        cout << "Starting BFS from node: " << source << endl;

        // Process the queue until empty.
        while (!pq.isEmpty()) {
            PQueue::PQElement* front = pq.peek();
            int current = front->dest;
            pq.dequeue();
            cout << "Visited node: " << current << endl;
            // Explore all neighbors of the current vertex.
            Node* currentNode = g.adjacencyList[current];
            while (currentNode != nullptr) {
                int neighbor = currentNode->dest;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    // Set the parent of the neighbor to be the current vertex.
                    parent[neighbor] = current;
                    pq.enqueue(neighbor, order++);  // Enqueue neighbor with increasing order value
                }
                currentNode = currentNode->next;
            }
        }



        delete[] visited;
        return parent;
    }





    // Helper DFS function that builds a DFS tree by adding tree edges
    void dfsRec(Graph &g, Graph &dfsTree, bool visited[], int source) {
        visited[source] = true;
        cout << "Visited node: " << source << endl;

        Node* current = g.adjacencyList[source];
        while (current != nullptr) {
            int neighbor = current->dest;
            if (!visited[neighbor]) {
                // tree edge
                dfsTree.addEdge(source, neighbor, current->weight);
                dfsRec(g, dfsTree, visited, neighbor);
            }
            current = current->next;
        }
    }

    Graph Algorithms::dfs(Graph &g, int source) {
        const int size = g.getNumberOfVertices();
        bool* visited = new bool[size];
        resetVisit(visited, size);

        // Create a new graph to hold the DFS tree
        Graph dfsTree(size);


        dfsRec(g, dfsTree, visited, source);

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                dfsRec(g, dfsTree, visited, i);
            }
        }

        delete[] visited;
        return dfsTree;
    }

    /**
     *
     * @param dist dist from one node
     * @param visited
     * @param distSize
     * @return
     */
    int minDist(const int* dist, const bool* visited, const int distSize) {
        int min = INFINITY;
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
        int* dist = new int[size]; // array of the shortest path
        int* prev = new int[size]; // array to store the previous node for each node

        initDistance(dist, size);
        for (int i = 0; i < size; i++) {
            prev[i] = -1; // Initialize prev array to -1, indicating no previous node
        }

        bool* visited = new bool[size];
        resetVisit(visited, size);

        PQueue pq(size); // add graph size to PQ
        dist[source] = 0; // starting point

        for (int i = 0; i < size; i++) {
            const int temp = minDist(dist, visited, size);
            if (temp == -1) { // if dist is negative, dijkstra will fail
                cout << "Found negative dist, dijkstra will fail" << endl;
                break;
            }
            visited[temp] = true;
            Node* current = g.adjacencyList[temp];
            while (current != nullptr) {
                const int neighbor = current->dest; // neighbor node
                const int weight = current->weight; // neighbor weight
                // checks a few conditions
                // 1) if node already visited
                // 2) checks if (the current dist path plus new weight) is less than a neighbor total path
                if (!visited[neighbor] && dist[temp] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[temp] + weight; // add the new weight to the dist
                    prev[neighbor] = temp; // update the previous node for this neighbor
                    pq.enqueue(neighbor, dist[neighbor]);
                }
                current = current->next; // go to the next node
            }
        }

        // Output the shortest distances and paths from the source node
        cout << "Shortest distances from source node " << source << endl;
        for (int i = 0; i < size; i++) {
            cout << "Node: " << i << " dist: " << dist[i] << " Path: ";
            printPath(prev, i); // print the path from source to node i
            cout << endl;
        }

        // free memory
        delete[] dist;
        delete[] visited;
        delete[] prev;
    }




    Graph Algorithms::prim(Graph &g) {
    const int size = g.getNumberOfVertices();
    bool* visited = new bool[size];  // To track which nodes are in the MST
    int* key = new int[size];        // Key values for vertices
    Graph MstGraph(size);

    resetVisit(visited, size);
    initDistance(key, size);

    PQueue pq(size);
    key[0] = 0;
    pq.enqueue(0, key[0]);

    // Perform Prim algorithm and build the MST graph
    while (!pq.isEmpty()) {
        PQueue::PQElement *current = pq.dequeue(); // Pick the node with the smallest key value
        if (visited[current->dest]) {
            continue;
        }
        visited[current->dest] = true;  // Mark the node as visited

        Node* currentNode = g.adjacencyList[current->dest];
        while (currentNode != nullptr) {
            const int neighbor = currentNode->dest;
            const int weight = currentNode->weight;
            // Check if the neighbor is not visited and the current edge weight is less than its current key
            if (!visited[neighbor] && weight < key[neighbor]) {
                key[neighbor] = weight;            // Update the key value
                pq.enqueue(neighbor, key[neighbor]); // Enqueue the neighbor with the new key
                MstGraph.addEdge(current->dest, neighbor, weight);
            }
            currentNode = currentNode->next;
        }
    }



    // Cleanup
    delete[] visited;
    delete[] key;

    // Return the MST graph (containing edges that are part of the MST)
    return MstGraph;
}







    /**
     * 
     * @param g Graph
     * @param source Node
     */
    Graph Algorithms::kruskal(Graph &g, int source) {




        return g;
    }
}






