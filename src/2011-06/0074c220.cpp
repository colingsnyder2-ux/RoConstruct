// from server: 40% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    typedef void (__thiscall *Function)(S *);
    unsigned int *vtable = *(unsigned int **)this;
    Function p = (Function)(vtable[6]);
    p(this);
}
