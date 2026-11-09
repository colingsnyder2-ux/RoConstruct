// from server: 100% by atomic.potato
struct S
{
    virtual void f(int);
    void g();
};

void S::f(int)
{
}

void S::g()
{
    ((void (__thiscall *)(S *, int))(*(void ***)this)[0x6c])(this, 0);
}
