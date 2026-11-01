// from server: 100% by king_originala
struct Node {
    int field0;
    int index;
    int* f();
};

struct NodeArray {
    Node** data;
    int count;
    int capacity;
    void resize(int size, Node* value);
};

struct Source {
    char padding[36];
    NodeArray nodes;
    void remove(Node* node);
};

struct Kernel {
    char padding[16];
    Source* source;
    NodeArray pending;
    void remove(Node* node);
};

void Kernel::remove(Node* node)
{
    source->remove(node);
    pending.resize(0, 0);

    NodeArray& nodes = source->nodes;
    int index = *node->f();
    Node* last = nodes.data[nodes.count - 1];
    nodes.data[index] = last;
    *last->f() = index;
    nodes.resize(nodes.count - 1, 0);
    *node->f() = -1;
}
