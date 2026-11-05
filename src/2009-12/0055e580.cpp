// from server: 63% by atomic.potato
struct Node {
    char pad0[0x10];
    int key;
    char pad14[0x40];
    Node* left;
    Node* right;
};

struct Job {
    char pad0[4];
    Node* root;
};

struct Result {
    int found;
    Node* node;
};

struct NetworkOwnerJob {
    char pad0[4];
    Node* root;
    bool find(int key, Result* out);
};

bool NetworkOwnerJob::find(int key, Result* out) {
    Node* n = this->root;
    Node* found = 0;
    bool less = true;
    while (n) {
        less = key < n->key;
        found = n;
        if (less)
            n = n->left;
        else
            n = n->right;
    }
    out->found = less ? 0 : 1;
    if (found) {
        out->node = found;
        return true;
    }
    out->node = 0;
    return true;
}
