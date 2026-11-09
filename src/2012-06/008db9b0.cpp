// from server: 41% by tajop
struct Node {
    virtual void run();
    int unused;
    int a;
    int b;
    int c;
    int extra;
    Node(int x, int y, int z) : a(x), b(y), c(z) {}
};

struct Ret {
    Node* p;
    Ret(Node* q) : p(q) {}
};

struct Holder {
    void* p;
    Holder() : p(0) {}
    void release() { operator delete(p); }
};

Ret make(int a, int b, int c);

Ret make(int a, int b, int c) {
    Holder h;
    Ret r(new Node(a, b, c));
    h.release();
    return r;
}
