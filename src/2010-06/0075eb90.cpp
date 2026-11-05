// from server: 67% by atomic.potato
struct V {
    virtual void v0();
    virtual int v1();
};

struct S {
    char pad[4];
    V* p;
    bool f(V* other);
};

bool S::f(V* other) {
    if (p == 0)
        return false;
    if (other == 0)
        return false;
    int a = p->v1();
    int b = other->v1();
    return a >= b;
}
