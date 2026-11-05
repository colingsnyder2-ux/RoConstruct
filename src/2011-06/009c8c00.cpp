// from server: 32% by atomic.potato
struct S
{
    virtual void f();
    virtual void g();
};

void S::f()
{
    int *vtable = *(int **)this;
    ((void (__thiscall *)(S *))vtable[3])(this);
    ((void (__thiscall *)(S *))vtable[0])(this);
}
