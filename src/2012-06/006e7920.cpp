// from server: 63% by atomic.potato
extern "C" void __cdecl sub_4015a0();
extern "C" void* __cdecl sub_6e0870();

struct Inner {
    virtual bool f(void*, int);
};

struct Outer {
    bool __cdecl g(Inner*);
};

bool Outer::g(Inner* p) {
    sub_4015a0();
    void* q = sub_6e0870();
    void* r = 0;
    if (!p->f(&r, 1))
        return false;
    *(void**)this = r;
    return true;
}
