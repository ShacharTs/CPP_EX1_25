#include <iostream>
#include "mainHeader.hpp"
#include "Algorithms.hpp"
using namespace std;



/**
 * Notes: this code was written in C++ version 17
 * g++ version: g++ (Rev3, Built by MSYS2 project) 14.2.0
 * from testing this code might NOT WORK on a lower version of c++ or g++
 *
 */

int main() {
    int userInput;
    cout << "Hello please choose which method do you want to use\n"
    << "For pre made graph please type 1 ,for Manual input please press 2 :";
    cin >> userInput;





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

}