// from server: 33% by atomic.potato
struct S
{
    void (__thiscall *f0)(S *);
    void (__thiscall *f4)(S *);
    void (__thiscall *f8)(S *);
    void (__thiscall *f12)(S *);
    void (__thiscall *f16)(S *);
    int f();
};

int S::f()
{
    f16(this);
    f0(this);
    return 0;
}
