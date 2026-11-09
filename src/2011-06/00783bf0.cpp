// from server: 26% by atomic.potato
extern "C" void* __cdecl sub_80A05E(unsigned int size);
extern "C" void* __cdecl sub_783380();

struct Node {
    Node* next;
    Node* prev;
    Node* parent;
    char pad[0x39 - 0x0C];
    unsigned char flag39;
};

struct Inner {
    Node* node;
    char pad[0x10 - 0x04];
    void* p10;
    void* p14;
    void* p18;
    void* p1c;
};

struct S {
    void* field0;
    Node* field4;
    void* field8;
    Inner inner;
    S* init();
};

S* S::init() {
    Node* n = (Node*)sub_783380();
    field4 = n;
    n->flag39 = 1;
    n->next = n;
    n->prev = n;
    n->parent = n;
    field8 = 0;
    void* mem = sub_80A05E(4);
    if (mem != 0) {
        *(Inner**)mem = &inner;
    } else {
        mem = 0;
    }
    inner.node = (Node*)mem;
    inner.p10 = 0;
    inner.p14 = 0;
    inner.p18 = 0;
    inner.p1c = 0;
    return this;
}
