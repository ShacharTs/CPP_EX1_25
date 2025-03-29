#include <iostream>

#include "Algorithms.hpp"


using namespace std;




/**
 * Notes: this code was written in C++ version 17
 * g++ version: g++ (Rev3, Built by MSYS2 project) 14.2.0
 * from testing this code will NOT WORK on a lower version of c++ or g++
 */


int main() {
    cout << "In the folder there is a png of the graph" << endl;

    graph::Graph preMadeGraph(8);

    preMadeGraph.addEdge(0,1,10);
    preMadeGraph.addEdge(0,2,1);
    preMadeGraph.addEdge(0,3,4);
    preMadeGraph.addEdge(1,4,0);
    preMadeGraph.addEdge(1,2,3);
    preMadeGraph.addEdge(2,3,2);
    preMadeGraph.addEdge(2,5,8);
    preMadeGraph.addEdge(3,5,2);
    preMadeGraph.addEdge(3,6,7);
    preMadeGraph.addEdge(4,5,1);
    preMadeGraph.addEdge(4,7,8);
    preMadeGraph.addEdge(5,7,9);
    preMadeGraph.addEdge(5,6,6);
    preMadeGraph.addEdge(6,7,12);

    int userAlgoInput;
    cout << "Please choose what algorithm  to run on pre made graph" <<endl;
    cout << "BFS type 1, DFS type 2, Dijkstra type 3, Prim type 4, Kruskal type 5" << endl;
    cin >> userAlgoInput;
    switch (userAlgoInput) {
        case 1:
            graph::Algorithms::bfs(preMadeGraph,0);
            break;
        case 2:
            graph::Algorithms::dfs(preMadeGraph,0);
            break;
        case 3:
            graph::Algorithms::dijkstra(preMadeGraph,0);
            break;
        case 4:
            graph::Algorithms::prim(preMadeGraph);
            break;
        case 5:
            graph::Algorithms::kruskal(preMadeGraph);
            break;
        default:
            cout << "Wrong input, please try again." << endl;
    }

    return 0;
}
