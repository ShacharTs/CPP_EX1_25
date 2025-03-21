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
                Node* curr = this->adjacencyList[i];
                while (curr != nullptr) {
                    const Node* temp = curr;
                    curr = curr->next;
                    delete temp;

                }
            }
            delete[] this->adjacencyList;
        }

        void Graph::addEdge(const int src, const int dest, int weight) {
             // creating new node for src to dest
             Node* newNode = new Node(dest,weight,adjacencyList[src]);
             adjacencyList[src] = newNode;
             // creating new node for dest to src
             newNode = new Node(src,weight,adjacencyList[dest]);
             adjacencyList[dest] = newNode;
        }

        void Graph::removeEdge(int src, int dest) {
             removeEdgeHelper(src,dest,nullptr,adjacencyList[src]);

             removeEdgeHelper(dest,src,nullptr,adjacencyList[dest]);
        }

        void Graph::removeEdgeHelper(int src, int dest, Node *prev, Node *current) {
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

        void Graph::print_graph() {
             for (int i = 0; i < this->numVertices; i++) {
                 cout << "Vertice: "<< i << " -> ";

                 // Traverse the linked list
                 Node* current = adjacencyList[i];
                 while (current != nullptr) {
                     cout << current->dest << " -> ";  // Print current dest
                     current = current->next; // Move to the next node
                 }
                 cout << "NULL" << endl;
             }
         }

};



