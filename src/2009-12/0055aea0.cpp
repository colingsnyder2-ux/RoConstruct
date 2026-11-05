// from server: 64% by atomic.potato
struct Node {
    char pad0[4];
    Node* left;
    Node* right;
    char pad1[0x25 - 0xc];
    char color;
};

struct Tree {
    char pad0[4];
    Node* head;
};

struct Cmp {
    bool operator()(const void* a, const void* b) const;
};

struct ServerReplicator {
    char pad0[0x18];
    Tree tree;
    Node* find(const void* key);
};

Node* ServerReplicator::find(const void* key) {
    Node* x = tree.head->left;
    Node* y = tree.head;
    while (x->color == 0) {
        if (Cmp()(x + 1, key)) {
            x = x->right;
        } else {
            y = x;
            x = x->left;
        }
    }
    return y;
}
