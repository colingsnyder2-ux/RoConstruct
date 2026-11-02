// from server: 100% by tajop
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char value;
    char color;
    char isnil;
};

struct TreeIterator {
    Node* ptr;
    void inc();
};

void TreeIterator::inc() {
    if (ptr->isnil) {
    } else if (!ptr->right->isnil) {
        Node* p = ptr->right;
        while (!p->left->isnil)
            p = p->left;
        ptr = p;
    } else {
        Node* p;
        while (!(p = ptr->parent)->isnil && ptr == p->right)
            ptr = p;
        ptr = p;
    }
}
