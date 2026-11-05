// from server: 44% by atomic.potato
struct Inner {
    virtual void f(void*, void*);
};

struct S {
    char pad[0x20];
    Inner* p;
    void func(void*, void*);
};

extern "C" void* __cdecl sub_6e7ce0(void*);

void S::func(void* a, void* b)
{
    void* t;
    if (a)
        t = sub_6e7ce0(a);
    else
        t = 0;
    Inner* q = p;
    void* r = t;
    q->f(r, b);
}
