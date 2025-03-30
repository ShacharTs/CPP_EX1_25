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
            // safety check
            if (!front) {
                break;
            }

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
                    pq.enqueue(current, neighbor, order++);
                }
                currentNode = currentNode->next;
            }
            delete front;
            delete currentNode;
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

    // Initialize distance array and previous pointer array.
    initDistance(dist, size);
    for (int i = 0; i < size; i++) {
        prev[i] = -1;
    }

    // Initialize visited array.
    bool* visited = new bool[size];
    resetVisit(visited, size);

    // Create a priority queue with capacity equal to the number of vertices.
    PQueue<Node> pq(size);
    dist[source] = 0;     // Starting point: distance to source is zero.

    // Enqueue the source vertex.
    // If your enqueue expects (source, dest, weight), use -1 for source (no predecessor).
    pq.enqueue(-1, source, dist[source]);

    // Main loop: Process nodes until the PQ is empty.
    while (!pq.isEmpty()) {
        // Extract the node with the smallest tentative distance.
        Node* current = pq.dequeue();
        int u = current->dest;
        delete current;  // Free the dequeued node.

        // Skip if this node has already been processed.
        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        // Relax all edges from u.
        Node* adj = g.adjacencyList[u];
        while (adj != nullptr) {
            int neighbor = adj->dest;
            int weight = adj->weight;

            // Check for negative weights.
            if (weight < 0) {
                delete[] dist;
                delete[] visited;
                delete[] prev;
                throw std::invalid_argument("Negative weight encountered in Dijkstra.");
            }

            // Relaxation step.
            if (!visited[neighbor] && dist[u] + weight < dist[neighbor]) {
                dist[neighbor] = dist[u] + weight;
                prev[neighbor] = u;
                // Enqueue the updated neighbor.
                pq.enqueue(u, neighbor, dist[neighbor]);
                // Optionally, record the edge in the resulting shortest path tree.
                dijkstraGraph.addEdge(u, neighbor, weight);
            }
            adj = adj->next;
        }
    }

    // Output the shortest path and distance from the source to the last vertex.
    int dest = size - 1;
    cout << "Shortest path from " << source << " to " << dest << ": ";
    printPath(prev, dest);
    cout << " (distance: " << dist[dest] << ")" << endl;

    // Clean up memory.
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

    // Allocate and initialize arrays.
    bool* visited = new bool[size];
    int* key = new int[size];
    int* parent = new int[size];

    resetVisit(visited, size);      // Set all visited[] values to false.
    initDistance(key, size);        // Set all keys to INT_MAX.
    for (int i = 0; i < size; i++) {
        parent[i] = -1;             // Initialize parent array.
    }

    // Create a priority queue with capacity equal to the number of vertices.
    PQueue<Node> pq(size * size);


    // Start with vertex 0: key is 0, and there is no parent (-1).
    key[0] = 0;
    pq.enqueue(-1, 0, key[0]);

    int totalMSTCost = 0;

    // Process nodes until the priority queue is empty.
    while (!pq.isEmpty()) {
        // Extract the node with the smallest key.
        Node* current = pq.dequeue();
        int u = current->dest;
        delete current;  // Free the node after extraction.

        // Skip if this vertex was already visited.
        if (visited[u])
            continue;
        visited[u] = true;

        // If u is not the starting vertex, add its key to the MST cost.
        if (parent[u] != -1) {
            totalMSTCost += key[u];
        }

        // Explore all neighbors of vertex u.
        Node* adj = g.adjacencyList[u];
        while (adj != nullptr) {
            int v = adj->dest;
            int w = adj->weight;
            // If v is not yet in the MST and the edge (u,v) is lighter than current key[v],
            // update key[v] and record u as its parent.
            if (!visited[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.enqueue(u, v, key[v]);
            }
            adj = adj->next;
        }
    }

    cout << "Total MST cost: " << totalMSTCost << endl;

    // Build the MST graph from the parent array.
    Graph mstGraph(size);
    for (int v = 1; v < size; v++) {
        int u = parent[v];
        mstGraph.addEdge(u, v, key[v]);
        cout << "Adding Edge to MST graph: (" << u << ", " << v << ") with weight = " << key[v] << endl;
    }

    // Clean up allocated memory.
    delete[] visited;
    delete[] key;
    delete[] parent;

    return mstGraph;
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