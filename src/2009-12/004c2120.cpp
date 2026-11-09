// from server: 89% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    void **p = *(void ***)((char *)this + 0x24);
    void *v = *(void **)((char *)p + 0x238);
    return ((int (__thiscall *)(void *))*(void **)v)((char *)p + 0x238);
}
