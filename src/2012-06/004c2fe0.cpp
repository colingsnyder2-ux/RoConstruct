// from server: 87% by tajop
struct Key {
    int x, y, z;
};

inline bool operator<(const Key& a, const Key& b) {
    if (a.x < b.x) return true;
    if (a.x != b.x) return false;
    if (a.y < b.y) return true;
    if (a.y != b.y) return false;
    return a.z < b.z;
}

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    Key key;
    int value;
    char color;
    char isnil;
};

struct Tree {
    int comp;
    Node* head;
    Node* lbound(const Key& k);
};

Node* Tree::lbound(const Key& k) {
    Node* where = head;
    Node* p = where->parent;
    while (!p->isnil) {
        if (p->key < k) {
            p = p->right;
        } else {
            where = p;
            p = p->left;
        }
    }
    return where;
}
