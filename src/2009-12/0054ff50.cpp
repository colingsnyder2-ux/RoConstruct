// from server: 68% by atomic.potato
struct S_func_0052f670
{
    int m_x;
    int f();
};

int S_func_0052f670::f()
{
    return m_x;
}

struct S
{
    int f();
};

int S::f()
{
    S_func_0052f670 *p = *(S_func_0052f670 **)((char *)this + 0x108);
    int result = p->f();
    int *vtable = *(int **)result;
    return ((int (__thiscall *)(int *, int))vtable[0x2c])(vtable, 1);
}
