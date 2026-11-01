// from server: 100% by king_originala
struct Node {
    int field0;
    int index;
    int references;
};

struct Source {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Node *get(int index);
};

struct NodeArray {
    Node **data;
    int size;

    void resize(int count, int flag);
};

struct S {
    char padding[12];
    NodeArray nodes;

    void f(Source *source);
};

void S::f(Source *source)
{
    for (int i = 0; i < 2; ++i) {
        Node *node = source->get(i);
        if (node) {
            --node->references;
            int index = node->index;
            if (index >= 0 && node->references == 0) {
                NodeArray *array = &nodes;
                Node *last = array->data[array->size - 1];
                array->data[index] = last;
                last->index = index;
                array->resize(array->size - 1, 0);
                node->index = -1;
            }
        }
    }
}
