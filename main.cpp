#include <iostream>
#include "mainHeader.hpp"
#include "Algorithms.hpp"
#include <cstdlib>

using namespace std;




/**
 * Notes: this code was written in C++ version 17
 * g++ version: g++ (Rev3, Built by MSYS2 project) 14.2.0
 * from testing this code might NOT WORK on a lower version of c++ or g++
 */

int main() {
    bool vaild = false;
    while (!vaild) {
        int userInput;
        cout << "Hello please choose which method do you want to use\n"
        << "For pre made graph please type 1 ,for Manual input please press 2 :";
        cin >> userInput;

        switch (userInput) {
            case 1:
                preMade();
                vaild = true;
                break;
            case 2:
                userManual();
                vaild = true;
                break;
            default:
                cout << "Wrong input, please try again.\n";
                break;
        }
    }



    return 0;
}

void userManual() {
    int size;
    while (true) {
        cout << "Please choose the size of the graph do want to create: ";
        cin >> size;
        if (size > 1) {
            break;
        }
    }

    cout << "User graph size is: " << size;
    graph::Graph graph(size);
}

void preMade() {
    cout << "There is a png file that show the pre made graph" << endl;


    while (true) {
        char userInput;
        cout << "Do you want to see a visual of the pre made graph ?: y/n" << endl;
        cin >> userInput;
        if (userInput == 'y' || userInput == 'Y') {
            #ifdef _WIN32
                        system("start pre_made_graph.png");
            #elif __APPLE__
                        system("open pre_made_graph.png");
            #else
                        system("xdg-open pre_made_graph.png");
            #endif
            break;
        } else if (userInput == 'n' || userInput == 'N') {
            break;
        } else {
            cout << "Invalid input. Please enter y or n." << endl;
        }
    }

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




}