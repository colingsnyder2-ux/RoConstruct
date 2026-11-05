// from server: 100% by tajop
struct Value { double d; int a[8]; };
struct Node { Value value; Node* next; };

struct NodeConstructor {
    void* alloc;
    Node* node;
    bool nodeConstructed;
    bool valueConstructed;
    void construct(const Value& v);
};

void NodeConstructor::construct(const Value& v) {
    Node tmp;
    nodeConstructed = false;
    valueConstructed = false;
    node = (Node*)operator new(sizeof(Node));
    if (node) {
        Node* p = node;
        p->value = tmp.value;
        p->next = 0;
    }
    Node* q = node;
    nodeConstructed = true;
    if (q) {
        q->value = v;
    }
    valueConstructed = true;
}
