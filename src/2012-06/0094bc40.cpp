// from server: 48% by atomic.potato
struct S
{
    int f(int);
};

typedef int (__thiscall *Fn)(void *, int);

int S::f(int a)
{
    Fn p;
    p = *(Fn *)(*(int **)this + 12);
    ((void (__thiscall *)(void *, int))0x9481d0)(this, a);
    return p(this, a);
}
