// from server: 60% by atomic.potato
struct S_func_004a1480
{
    int f();
};

int S_func_004a1480::f()
{
    int *p = *(int **)((char *)this + 0x98);
    if (p == 0)
        return 0x8004020a;

    int *vtable = *(int **)p;
    int (__thiscall *fn)(int *) = (int (__thiscall *)(int *))vtable[5];
    return fn(p);
}
