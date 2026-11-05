// from server: 81% by atomic.potato
struct S
{
    int f();
    int g();
};

int S::f()
{
    if (g())
        return 0;
    return ((int (__thiscall *)(S *))(*(int **)this + 0x6c))(this);
}
