#ifndef NODE_HPP
#define NODE_HPP


struct Node {
    int source;
    int dest;
    int weight;
    Node* next;
    Node(const int source,const int dest, const int weight, Node* next = nullptr) : source(source), dest(dest), weight(weight), next(next) {}
};

#endif //NODE_HPP
