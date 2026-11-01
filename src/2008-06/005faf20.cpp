// from server: 100% by king_originala
struct Node;

struct Array {
    Node** data;
    int size;
    void resize(int count, Node* value);
};

struct Node {
    char reserved0[4];
    int index;
    char reserved1[20];
    Array children;

    const void* get();
};

struct S {
    char reserved[12];
    Array entries;

    void func_005faf20(Node* node);
};

void S::func_005faf20(Node* node)
{
    node->get();
    for (int i = 0; i < node->children.size; ++i) {
        Node* child = node->children.data[i];
        int index = child->index;
        if (index >= 0) {
            Array* array = &entries;
            Node* last = array->data[array->size - 1];
            array->data[index] = last;
            last->index = index;
            array->resize(array->size - 1, 0);
            child->index = -1;
        }
        func_005faf20(child);
    }
}
