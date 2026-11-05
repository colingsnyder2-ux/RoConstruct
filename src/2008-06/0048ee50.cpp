// from server: 100% by atomic.potato
extern "C" void __cdecl SignalDesc(void *);

struct S
{
    char pad[12];
    void *value;

    void f();
};

void S::f()
{
    void *p = value;
    SignalDesc(p);
    if (p)
    {
        void **v = *(void ***)((char *)p + 16);
        ((void (__thiscall *)(void *, int))v[0])((char *)p + 16, 1);
    }
}
