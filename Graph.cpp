#include <iostream>
#include "Graph.hpp"


using namespace std;

namespace graph {
         Graph::Graph(const int vertices) {
            this->numVertices = vertices;
            this->adjacencyList = new Node*[this->numVertices];

            cout << "Graph Constructor initializing" << endl;
            for (int i = 0;i<this->numVertices;i++) {
                this->adjacencyList[i] = nullptr;
            }
        }

        Graph::~Graph() {
            cout << "Graph Destructor cleaning" << endl;
            for (int i = 0; i < this->numVertices; i++) {
                const Node* curr = this->adjacencyList[i];
                while (curr != nullptr) {
                    const Node* temp = curr;
                    curr = curr->next;
                    delete temp;

                }
            }
            delete[] this->adjacencyList;
        }

        /**
         * Connect 2 nodes together from both side
         * @param src source node
         * @param dest destination node
         * @param weight node weight
         */
        void Graph::addEdge(const int src, const int dest, int weight) {
             // creating new node for src to dest
             Node* newNode = new Node(dest,weight,adjacencyList[src]);
             adjacencyList[src] = newNode;
             // creating new node for dest to src
             newNode = new Node(src,weight,adjacencyList[dest]);
             adjacencyList[dest] = newNode;
        }




        /**
         * Undirected graph needs to remove both side to fully remove both edges
         * @param src the source node
         * @param dest the destination node
         */
        void Graph::removeEdge(const int src, const int dest) {
             removeEdgeHelper(src,dest,nullptr,adjacencyList[src]);

             removeEdgeHelper(dest,src,nullptr,adjacencyList[dest]);
             cout << "Removed edge (" <<src << "," << dest <<")" << endl;

        }

        /**
         *
         * A helper method to remove the edge in recursive way
         * @param src the source node
         * @param dest the destination node
         * @param prev a pointer to previous node
         * @param current a pointer to current node
         */
        void Graph::removeEdgeHelper(const int src, const int dest, Node *prev, Node *current) {
             // base case if current = nullptr
             if (current == nullptr) {
                 return;
             }
             // if current node matches the destination, remove it
             if (current->dest == dest) {
                 if (prev == nullptr) {
                     adjacencyList[src] = current->next;
                 }else {
                     prev->next = current->next;
                 }
                 delete current;
                 return;
             }
             // recursively call on the next node
             removeEdgeHelper(src,dest,current,current->next);
         }

        /**
         * This method will print each node it path in the graph in linear way
         */
        void Graph::print_graph() {
             for (int i = 0; i < this->numVertices; i++) {
                 cout << "Vertex " << i << " -> ";

                 // Traverse the linked list for adjacency list of vertex i
                 Node* current = adjacencyList[i];

                 // Traverse the adjacency list and print destination and weight
                 while (current != nullptr) {
                     cout << "(" << current->dest << ", weight: " << current->weight << ") -> ";
                     current = current->next;  // Move to the next node
                 }

                 cout << "NULL" << endl;
             }
        }

        int Graph::getNumberOfVertices() {
             return this->numVertices;
        }

        int getWeight(const Node* current) {
             return current->weight;
        }
};



