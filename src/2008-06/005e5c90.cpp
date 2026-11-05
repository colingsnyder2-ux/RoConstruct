// from server: 100% by king_originala
struct Frame {
    char data[0x30];
};

struct NodeData {
    char padding[0x14];
    NodeData* owner;
};

struct Node {
    char padding[0xa0];
    NodeData* data;
};

struct Pair {
    char padding[0xcc];
    float value;

    void set(const Frame& first, const Frame& second);
    void f();
};

struct S {
    char padding0[0x0c];
    Node* first;
    Node* second;
    char padding1[0x14];
    Frame frame0;
    Frame frame1;
    Pair* pair;
    float value;

    Pair* f();
};

Pair* S::f()
{
    int reversed = second->data->owner != first->data;
    pair->set(reversed == 0 ? frame0 : frame1,
              reversed == 1 ? frame0 : frame1);
    Pair* p = pair;
    p->value = value;
    p->f();
    return pair;
}
