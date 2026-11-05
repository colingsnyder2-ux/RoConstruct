// from server: 24% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    void** v = *(void***)this;
    ((void (__thiscall *)(S*))v[3])(this);
    v = *(void***)this;
    ((void (__thiscall *)(S*))v[0])(this);
    return 0;
}
