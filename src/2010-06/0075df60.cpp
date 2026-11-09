// from server: 50% by atomic.potato
struct S_func_005e6b50
{
    char pad0[36];
    int m_x;
    void f(int a1);
};

void S_func_005e6b50::f(int a1)
{
    m_x = a1;
}

struct MultiJoint
{
    void *vtable;
    void f(int a1);
};

void MultiJoint::f(int a1)
{
    S_func_005e6b50 *p = (S_func_005e6b50 *)((void *(__thiscall *)(void *, int))(*(void ***)this)[2])(this, a1);
    p->f((int)this);
    ((void (__thiscall *)(S_func_005e6b50 *, int))0x786140)(p, a1);
}
