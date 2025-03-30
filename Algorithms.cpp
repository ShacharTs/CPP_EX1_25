#include "Algorithms.hpp"
#include "PQueue.hpp"
#include <iostream>
#include <climits>


using namespace  std;

namespace graph {
    // helper method to reset visited
    void resetVisit(bool* visited,const int graphSize) {
        for (int i = 0; i < graphSize; i++) {
            visited[i] = false;
        }
    }

    // helper method to reset dist
    void initDistance(int* dist,const int graphSize) {
        for (int i = 0; i < graphSize; i++) {
            dist[i] = INT_MAX;
        }
    }

    // helper function to print the path from source to node
    void printPath(int* prev, const int node) {
        if (node == -1) {
            return;
        }
        printPath(prev, prev[node]); // Recursively print a predecessor path
        cout << node << " ";
    }
    // helper method to call dist
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
     * Bfs method to look for all the nodes
     * @param g Graph
     * @param source Node
     */
    Graph Algorithms::bfs(Graph &g, const int source) {
        const int size = g.getNumberOfVertices();
        Graph bfsTree(size);

        // Track visited nodes.
        bool* visited = new bool[size];
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }

        // Use a priority queue for BFS order.
        PQueue<Node> pq(size);
        int order = 0;

        visited[source] = true;
        // Enqueue the source
        pq.enqueue(-1, source, order++);

        cout << "Starting BFS from node: " << source << endl;

        // Process the queue until empty.
        while (!pq.isEmpty()) {
            // Dequeue the front node.
            Node* front = pq.dequeue();
            if (!front) break; // safety check

            int current = front->dest;
            cout << "Visited node: " << current << endl;

            // Explore all neighbors of 'current'.
            Node* currentNode = g.adjacencyList[current];
            while (currentNode != nullptr) {
                int neighbor = currentNode->dest;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;

                    // Add edge (current -> neighbor) to the BFS tree.
                    // The weight is taken from the original graph's edge.
                    bfsTree.addEdge(current, neighbor, currentNode->weight);

                    // Enqueue the neighbor.
                    // Use the current node as the parent.
                    pq.enqueue(current, neighbor, order++);
                }
                currentNode = currentNode->next;
            }

            // Free the node returned by dequeue.
            delete front;
        }

        // Clean up memory.
        delete[] visited;

        // Return the BFS tree graph.
        return bfsTree;
    }



    // Helper DFS function that builds a DFS tree by adding tree edges
    void dfsRec(Graph &g, Graph &dfsTree, bool visited[], const int source) {
        visited[source] = true;
        cout << "Visited node: " << source << endl;
        Node* current = g.adjacencyList[source];
        while (current != nullptr) {
            const int neighbor = current->dest;
            if (!visited[neighbor]) {
                // tree edge
                dfsTree.addEdge(source, neighbor, current->weight);
                dfsRec(g, dfsTree, visited, neighbor);
            }
            current = current->next;
        }
    }

    /**
     * Dfs method to look for all the nodes
     * @param g graph
     * @param source start node
     * @return graph
     */
    Graph Algorithms::dfs(Graph &g, const int source) {
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
     * Dijkstra, check for the shortest path in graph when node got weight
     * @param g Graph
     * @param source Node
     */
    Graph Algorithms::dijkstra(Graph &g, const int source) {
    int size = g.getNumberOfVertices();
    int* dist = new int[size];    // Array for shortest path distances.
    int* prev = new int[size];    // Array to store the previous node for each vertex.
    Graph dijkstraGraph(size);

    initDistance(dist, size);
    for (int i = 0; i < size; i++) {
        prev[i] = -1; // Initialize prev array to -1, indicating no previous node.
    }

    bool* visited = new bool[size];
    resetVisit(visited, size);

    PQueue<Node> pq(size); // Priority queue with given capacity.
    dist[source] = 0;     // Starting point.

    // Enqueue the starting vertex. If enqueue expects (source, dest, weight),
    // pass -1 for the source since it has no predecessor.
    pq.enqueue(-1, source, dist[source]);

    for (int i = 0; i < size; i++) {
        const int temp = minDist(dist, visited, size);
        // No valid vertex left to process.
        if (temp < 0) {
            break;
        }
        visited[temp] = true;
        Node* current = g.adjacencyList[temp];

        while (current != nullptr) {
            const int neighbor = current->dest;   // Neighbor vertex.
            const int weight = current->weight;     // Edge weight.

            if (weight < 0) {
                delete[] dist;
                delete[] visited;
                delete[] prev;
                throw std::invalid_argument("Negative weight");
            }

            // Relaxation step: if the neighbor hasn't been visited and we find a shorter path.
            if (!visited[neighbor] && dist[temp] + weight < dist[neighbor]) {
                dist[neighbor] = dist[temp] + weight;  // Update distance.
                prev[neighbor] = temp;                // Update previous node.
                // Enqueue updated neighbor using three parameters.
                pq.enqueue(temp, neighbor, dist[neighbor]);
                dijkstraGraph.addEdge(temp, neighbor, weight);
            }
            current = current->next;  // Move to the next adjacent node.
        }
        // DO NOT delete 'current' here because it points to nodes in the graph's adjacency list.
    }

    // Output the shortest path and distance from the source to the last vertex.
    int dest = size - 1;
    cout << "Shortest path from " << source << " to " << dest << ": ";
    printPath(prev, dest);
    cout << " (distance: " << dist[dest] << ")" << endl;

    // Free allocated memory.
    delete[] dist;
    delete[] visited;
    delete[] prev;

    return dijkstraGraph;
}


    /**
     * Returns the MST of the graph using Prim's algorithm.
     *
     * @param g The input graph.
     * @return The MST as a new graph.
     */

    Graph Algorithms::prim(Graph &g) {
        int size = g.getNumberOfVertices();
        bool* visited = new bool[size];
        int* key = new int[size];
        int* parent = new int[size];

        resetVisit(visited, size);
        initDistance(key, size);
        for (int i = 0; i < size; i++) {
            parent[i] = -1;
        }

        PQueue<Node> pq(size);
        key[0] = 0;
        pq.enqueue(-1,0, key[0]);

        int totalMSTCost = 0;
        while (!pq.isEmpty()) {
            Node* current = pq.dequeue();
            int u = current->dest;
            delete current;

            if (visited[u]) continue;
            visited[u] = true;

            if (parent[u] != -1) {
                totalMSTCost += key[u];
            }

            // Explore neighbors
            Node* adj = g.adjacencyList[u];
            while (adj != nullptr) {
                int v = adj->dest;
                int w = adj->weight;
                if (!visited[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.enqueue(u,v, key[v]);
                }
                adj = adj->next;
            }
        }

        cout << "Total MST cost: " << totalMSTCost << endl;
        Graph MstGraph(size);
        for (int v = 1; v < size; v++) {
            int u = parent[v];
            MstGraph.addEdge(u, v, key[v]);
            cout << "Adding Edge to MST graph: (" << u << ", " << v << ") with weight = " << key[v] << endl;
        }
        // free memory
        delete[] visited;
        delete[] key;
        delete[] parent;

        return MstGraph;
    }



    /**
     * Returns the MST of the graph using Kruskal's algorithm.
     *
     * @param g The input graph.
     * @return The MST as a new graph.
    */
    Graph Algorithms::kruskal(Graph &g) {
        const int size = g.getNumberOfVertices();
        Graph mst(size);
        PQueue<Node> pq(size * size);
        UnionFind uf(size);
        int totalWeight = 0;

        // Enqueue all edges once (undirected: source < dest)
        for (int i = 0; i < size; i++) {
            Node* temp = g.adjacencyList[i];
            while (temp != nullptr) {
                if (temp->source < temp->dest)
                    pq.enqueue(temp->source, temp->dest, temp->weight);
                temp = temp->next;
            }
        }

        // Process edges in increasing order of weight
        while (!pq.isEmpty()) {
            Node* edge = pq.dequeue();
            int u = edge->source;
            int v = edge->dest;
            int w = edge->weight;

            // If edge doesn't form a cycle, add it to MST
            if (uf.find(u) != uf.find(v)) {
                mst.addEdge(u, v, w);
                totalWeight += w;
                cout << "Adding Edge to MST: (" << u << ", " << v << ") with weight = " << w << endl;
                uf.unionSets(uf.find(u), uf.find(v));
            }
            delete edge;
        }

        cout << "Total weight of MST: " << totalWeight << endl;
        return mst;
    }




}