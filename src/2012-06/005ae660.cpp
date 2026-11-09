// from server: 69% by atomic.potato
struct Node {
    char pad0[4];
    double key;
    char pad1[0x58];
    Node* left;
    Node* right;
};

struct Sender {
    char pad0[4];
    Node* root;
};

struct Result {
    int found;
    Node* node;
};

struct ErrorCompPhysicsSender {
    char pad0[0xc];
    Sender* sender;
    bool find(double* key, Result* out);
};

bool ErrorCompPhysicsSender::find(double* key, Result* out) {
    Sender* s = this ? this->sender : 0;
    Node* n = s ? s->root : 0;
    Node* cur = n ? (Node*)((char*)n - 0x60) : 0;
    bool al = true;
    Node* last = 0;
    if (cur) {
        double k = *key;
        while (cur) {
            last = cur;
            if (cur->key > k) {
                cur = cur->left;
                al = true;
            } else {
                cur = cur->right;
                al = false;
            }
            if (cur) cur = (Node*)((char*)cur - 0x60);
        }
    }
    out->found = al ? 0 : 1;
    out->node = last ? (Node*)((char*)last + 0x60) : 0;
    return true;
}
