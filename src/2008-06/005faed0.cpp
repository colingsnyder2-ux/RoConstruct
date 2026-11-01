// from server: 100% by colin
// from server: 87% by king_originala
struct Node {
    int field0;
    int index;
    int value;
    int field12;
    int field16;
    int field20;
    int field24;
    Node** children;
    int childCount;
};

struct NodeList {
    Node** data;
    int size;
    int capacity;

    void append(Node* const& node);
};

struct S {
    int field0;
    int field4;
    int field8;
    NodeList nodes;

    void visit(Node* node);
};

void S::visit(Node* node)
{
    for (int i = 0; i < node->childCount; ++i) {
        Node* child = node->children[i];
        if (child->value > 0) {
            NodeList* list = &nodes;
            Node* entry = child;
            child->index = list->size;
            list->append(entry);
        }
        visit(child);
    }
}

