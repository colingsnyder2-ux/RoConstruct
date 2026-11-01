// from server: 100% by king_originala
struct Primitive;

struct List {
    char data[0x1c];
    void remove(Primitive*);
};

struct Endpoint {
    char padding[0x18];
    List first;
    List second;
};

struct Primitive {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int query();

    char padding[8];
    Endpoint* a;
    Endpoint* b;
};

void f(Primitive* p)
{
    Endpoint* a = p->a;
    Endpoint* b = p->b;

    if (!p->query()) {
        a->second.remove(p);
        if (b)
            b->second.remove(p);
    } else {
        a->first.remove(p);
        b->first.remove(p);
    }
}
