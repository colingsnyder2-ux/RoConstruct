// from server: 91% by atomic.potato
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int, int);
};

struct S {
    Inner* GetInner();
    int DoThing(int);
    bool Method(int arg);
};

bool S::Method(int arg) {
    Inner* p = GetInner();
    if (p) {
        DoThing(p->v4(arg, 0));
        return true;
    }
    return false;
}
