// from server: 100% by colin
struct Inner {
    virtual Inner* f();
    virtual Inner* g();
    virtual Inner* h();
    virtual Inner* i();
};

struct Outer {
    char pad[0x34];
    Inner* inner;
    int get();
};

int Outer::get()
{
    Inner* p = inner;
    Inner* q = p->i();
    return *(int*)((char*)q + 0x2c);
}
