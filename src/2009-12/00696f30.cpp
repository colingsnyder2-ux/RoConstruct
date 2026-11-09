// from server: 100% by atomic.potato
struct S
{
    char pad[12];
    void* field;
    void f();
};

void S::f()
{
    void* p = field;
    if (p)
    {
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = *(Fn *)((char *)*(void **)p + 0x40);
        fn(p, 1);
    }
}
