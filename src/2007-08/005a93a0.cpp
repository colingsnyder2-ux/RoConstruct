// from server: 100% by colin
struct Inner {
    virtual Inner* a();
    virtual Inner* b();
    virtual Inner* c();
    virtual Inner* d();
};

struct Outer {
    char pad[0x34];
    Inner* inner;
    int get();
};

int Outer::get()
{
    Inner* p = inner;
    Inner* q = p->d();
    return *(int*)((char*)q + 0x38);
}
