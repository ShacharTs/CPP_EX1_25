#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

class UnionFind {
private:
    int* parent;
    int* rank;

public:
    explicit UnionFind(int size);
    ~UnionFind();

    int find(int x);
    void unionSets(int x, int y);
    bool sameSet(int x, int y);
};

#endif // UNIONFIND_HPP
