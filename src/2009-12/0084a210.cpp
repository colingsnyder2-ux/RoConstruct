// from server: 100% by atomic.potato
struct S
{
    void* pad0;
    void* p;
    int pad8;
    int value;

    void f();
};

void S::f()
{
    if (p && value != -1)
    {
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = *(Fn*)((char*)*(void**)p + 0x38);
        fn(p, value);
        value = -1;
    }
}
