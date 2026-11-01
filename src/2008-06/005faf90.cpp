// from server: 100% by king_originala
struct Node {
    int activeIndex;
    int freeIndex;
};

struct NodeArray {
    Node** data;
    int size;
    int capacity;

    void resize(int newSize, Node* value);
    void append(Node* const& value);
};

struct S {
    NodeArray active;
    NodeArray freeNodes;

    void process(Node* node);
    void activate(Node* node);
};

void S::activate(Node* node)
{
    int index = node->freeIndex;
    if (index >= 0) {
        NodeArray& nodes = freeNodes;
        Node* last = nodes.data[nodes.size - 1];
        nodes.data[index] = last;
        last->freeIndex = index;
        nodes.resize(nodes.size - 1, 0);
        node->freeIndex = -1;
    }

    node->activeIndex = active.size;
    Node* value = node;
    active.append(value);
    process(node);
}
