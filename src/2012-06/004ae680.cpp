// from server: 100% by tajop
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char value[12];
    char color;
    char isnil;
};

struct Iter {
    Node* ptr;
    Iter(Node* p) : ptr(p) {}
    Iter& operator++() {
        if (!ptr->isnil) {
            if (!ptr->right->isnil) {
                Node* n = ptr->right;
                while (!n->left->isnil)
                    n = n->left;
                ptr = n;
            } else {
                Node* p;
                while (!(p = ptr->parent)->isnil && ptr == p->right)
                    ptr = p;
                ptr = p;
            }
        }
        return *this;
    }
    Iter operator++(int) {
        Iter t = *this;
        ++*this;
        return t;
    }
};

struct Tree {
    int comp;
    Node* head;
    unsigned int size;
    void eraseSubtree(Node* n);
    Iter erase(Iter where);
    Iter erase(Iter first, Iter last);
};

Iter Tree::erase(Iter first, Iter last) {
    if (first.ptr == head->left && last.ptr == head) {
        eraseSubtree(head->parent);
        head->parent = head;
        size = 0;
        head->left = head;
        head->right = head;
        return Iter(head->left);
    }
    while (first.ptr != last.ptr)
        erase(first++);
    return Iter(first.ptr);
}
