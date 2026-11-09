// from server: 86% by atomic.potato
typedef void (__thiscall *Callback)(void *);

extern "C" void __stdcall CallTarget(void *, int);

struct S
{
    int f();
};

int S::f()
{
    void *p = *(void **)((char *)this - 0x48);
    Callback cb = *(Callback *)((char *)p + 0x38);
    cb((char *)this - 0x48);

    void *q = *(void **)((char *)this + 4);
    if (q)
        CallTarget(q, 0);

    return 0;
}
