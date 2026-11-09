// from server: 100% by king_originala
extern float __cdecl infinity();

struct State {
    char reserved[4];
    float value;
};

struct Node {
    int index;
    char reserved[40];
    State* state;
};

struct Array {
    Node** data;
    int size;

    void resize(int count, Node* value);
    void remove(Node* node);
};

struct Kernel {
    char reserved[16];
    Array* nodes;

    void removeNode(Node* node);
};

void Kernel::removeNode(Node* node)
{
    infinity();
    Array* array = nodes;
    int index = node->index;
    Node* last = array->data[array->size - 1];
    array->data[index] = last;
    last->index = index;
    array->resize(array->size - 1, 0);
    node->index = -1;
    array->remove(node);
    State* state = node->state;
    if (state)
        state->value = 0.0f;
}
