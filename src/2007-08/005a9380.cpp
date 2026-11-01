// from server: 100% by colin
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

struct Outer {
    char pad[0x34];
    Inner* inner;
    int get();
};

int Outer::get()
{
    Inner* p = inner;
    int r = p->f3();
    return *(int*)((char*)r + 0x20);
}
