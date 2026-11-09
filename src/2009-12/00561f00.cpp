// from server: 51% by atomic.potato
struct Node {
    char pad0[4];
    int key;
    char pad8[0x18];
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

struct Sender {
    char pad0[4];
    Job* job;
    bool find(int key, Result* out);
};

bool Sender::find(int key, Result* out) {
    Node* n = 0;
    if (this) {
        Job* j = *(Job**)((char*)this - 0xc + 4);
        Node* r = *(Node**)((char*)j + 0x20);
        r = (Node*)((int)r & 0xfffffffe);
        if (r) {
            r = (Node*)((char*)r - 0x20);
        } else {
            r = 0;
        }
        n = r;
        bool less = true;
        while (n) {
            if (key < n->key) {
                less = true;
                n = n->left;
            } else {
                less = false;
                n = n->right;
            }
            if (n) {
                n = (Node*)((char*)n - 0x20);
            }
        }
        out->found = less ? 0 : 1;
        if (n) {
            out->node = (Node*)((char*)n + 0x20);
        } else {
            out->node = 0;
        }
        return true;
    }
    return true;
}
