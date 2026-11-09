// from server: 100% by tester
struct Inner;

struct Vtbl1 {
    char pad[0x8c];
    Inner* (__thiscall *getInner)(void*);
};

struct Vtbl2 {
    char pad[0x1e8];
    void (__thiscall *doThing)(Inner*, int, int, int);
};

struct Inner {
    Vtbl2* vtbl;
};

struct Outer {
    Vtbl1* vtbl;
    void method(int a, int b, int c);
};

void Outer::method(int a, int b, int c)
{
    Inner* p = this->vtbl->getInner(this);
    if (p)
    {
        p->vtbl->doThing(p, a, b, c);
    }
}
