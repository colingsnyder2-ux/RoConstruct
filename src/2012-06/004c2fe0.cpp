// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Key { int x, y, z; };
inline bool operator<(const Key& a, const Key& b) {
    return a.x < b.x || (a.x == b.x && (a.y < b.y || (a.y == b.y && a.z < b.z)));
}
struct Node { Node* left; Node* parent; Node* right; Key key; int value; char color; char isnil; };
struct Tree { int comp; Node* head; Node* lbound(const Key& k); };
Node* Tree::lbound(const Key& k) {
    Node* where = head;
    Node* p = where->parent;
    while (!p->isnil) {
        if (p->key < k) p = p->right;
        else { where = p; p = p->left; }
    }
    return where;
}
