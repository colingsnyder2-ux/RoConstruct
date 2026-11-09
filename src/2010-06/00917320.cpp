// from server: 27% by atomic.potato
struct S
{
    virtual void f();
};

void S::f()
{
    ((void (__thiscall *)(S *))(*(void ***)this)[0])(this);
}
