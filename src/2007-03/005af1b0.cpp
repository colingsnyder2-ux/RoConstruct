// from server: 100% by tester
struct Node {
    char pad0[8];
    void* key1;
    void* key2;
    Node* left;
    Node* right;
};

struct Geometry {
    char pad0[8];
    Node* root;
    int key;
};

Node* find(Geometry* a, Geometry* b) {
    Geometry* smaller;
    if (a->key < b->key)
        smaller = a;
    else
        smaller = b;
    Node* n = smaller->root;
    while (n) {
        if (a == n->key1 && b == n->key2)
            return n;
        if (a == n->key2 && b == n->key1)
            return n;
        if (smaller == n->key1)
            n = n->left;
        else
            n = n->right;
    }
    return 0;
}
