// from server: 85% by atomic.potato
struct S
{
    int __stdcall f();
};

int __stdcall S::f()
{
    int (__thiscall **vtable)(S *);
    vtable = *(int (__thiscall ***)(S *))this;
    vtable[14](this);
    return 0;
}
