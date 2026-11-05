// from server: 100% by king_originala
struct ResetValue {
    void reset();
    unsigned long words[2];
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct Tree {
    char padding[24];
    Node* head;
    unsigned long size;
    void erase(Node* node);
    void clear();
};

struct Service {
    char padding[12];
    unsigned long state;
    ResetValue value;
    Tree tree;
    void clear();
};

__forceinline void Tree::clear()
{
    erase(head->parent);
    head->parent = head;
    size = 0;
    head->left = head;
    head->right = head;
}

void Service::clear()
{
    value.reset();
    tree.clear();
    state = state == 1 ? 0 : 3;
}
