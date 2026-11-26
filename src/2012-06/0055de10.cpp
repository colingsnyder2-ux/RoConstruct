// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char pad[0x61];
    char isnil;
};
struct TreeIterator {
    Node* ptr;
    void dec();
};
void TreeIterator::dec() {
    if (ptr->isnil) {
        ptr = ptr->right;
    } else if (!ptr->left->isnil) {
        Node* p = ptr->left;
        while (!p->right->isnil)
            p = p->right;
        ptr = p;
    } else {
        Node* p;
        while (!(p = ptr->parent)->isnil && ptr == p->left)
            ptr = p;
        if (!ptr->isnil)
            ptr = p;
    }
}