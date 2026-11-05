// from server: 100% by atomic.potato
struct S
{
    int pad0;
    void* p;
    void* q;

    void f();
};

void S::f()
{
    if (p && q)
    {
        typedef void (__thiscall *Fn)(void*, void*);
        Fn fn = *(Fn*)((char*)*(void**)p + 0x30);
        fn(p, q);
        q = 0;
    }
}
