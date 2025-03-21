#include "Graph.cpp"
// push test
int main() {
    graph::Graph g(5);
    // Add edges
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    cout << "Graph after adding edges:" << endl;
    g.print_graph();  // Print the graph after adding edges

    // Remove some edges and print the graph after each removal
    cout << "\nRemoving edge 1 -> 4:" << endl;
    g.removeEdge(1, 4);
    g.print_graph();  // Print the graph after removing edge 1 -> 4

    cout << "\nRemoving edge 0 -> 1:" << endl;
    g.removeEdge(0, 1);
    g.print_graph();  // Print the graph after removing edge 0 -> 1

    cout << "\nRemoving edge 3 -> 4:" << endl;
    g.removeEdge(3, 4);
    g.print_graph();  // Print the graph after removing edge 3 -> 4

}