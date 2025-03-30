#include "UnionFind.hpp"

UnionFind::UnionFind(int size) {
    parent = new int[size];
    rank = new int[size];

    for (int i = 0; i < size; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

/**
 * find node in graph
 * @param x node
 */
int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

/**
 * connect 2 nodes
 * @param x node
 * @param y node
 */
void UnionFind::unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
        return;

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

/**
 * check if 2 nodes are in the same graph
 * @param x node
 * @param y node
 * @return if both in the same graph
 */
bool UnionFind::sameSet(int x, int y) {
    return find(x) == find(y);
}


