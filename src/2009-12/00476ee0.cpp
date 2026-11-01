// from server: 48% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    void **p = *(void ***)(this + 4);
    if (p)
        ((void (__thiscall *)(void *))(*(void ***)p)[2])(p);
    return 0;
}
