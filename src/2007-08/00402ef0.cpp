// from server: 88% by colin
struct Inner {
    virtual int f();
};

struct Outer {
    char pad[0x30];
    Inner* inner;
};

int g(Outer* p)
{
    Inner* q = p->inner;
    int (**vtbl)(Inner*) = *(int (***)(Inner*))q;
    return vtbl[0](q);
}
