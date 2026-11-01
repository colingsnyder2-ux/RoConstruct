// from server: 45% by atomic.potato
struct Node {
    Node* next;
    char pad[0x2c];
};

struct Inner {
    char pad0[4];
    void clear();
};

struct S {
    char pad0[4];
    Node** begin;
    unsigned int count;
    Node** end;
    void f();
};

void Inner::clear() {
    Node* p = *(Node**)this;
    *(Node**)this = 0;
    while (p) {
        Node* n = p->next;
        Inner* inner = (Inner*)((char*)p - 0x30 + 4);
        inner->clear();
        operator delete((char*)p - 0x30);
        p = n;
    }
}

void S::f() {
    if (begin) {
        Node** e = end;
        Node** p = begin + count;
        if (e != p) {
            do {
                Node* n = *e;
                *e = 0;
                while (n) {
                    Node* nx = n->next;
                    Inner* inner = (Inner*)((char*)n - 0x30 + 4);
                    inner->clear();
                    operator delete((char*)n - 0x30);
                    n = nx;
                }
                ++e;
            } while (e != p);
        }
        operator delete(begin);
    }
}
