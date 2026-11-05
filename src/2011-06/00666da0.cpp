// from server: 70% by atomic.potato
struct S
{
    int enabled;
    int pad1;
    int pad2;
    int pad3;
    int active;
    int (**vtable)();
    void __cdecl f(void *);
};

void S::f(void *arg)
{
    if (active)
        ((void (__thiscall *)(void *, void *))vtable[0])(this, arg);
}
