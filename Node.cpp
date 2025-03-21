


/**
 * basic Node struct
 *
 * @param dest The destination vertex index.
 * @param weight The weight of the edge connecting the nodes.
 * @param next Pointer to the next neighbor node in the adjacency list.
 */
struct Node {
    int dest;
    int weight;
    Node* next;

    Node(const int dest, int weight, Node* next = nullptr) : dest(dest), weight(weight), next(next) {}
};
