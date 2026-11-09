// from server: 72% by atomic.potato
struct S {
    int f10;
    int f14;
    int f18;
    int f();
};

int S::f()
{
    return ((int (__thiscall *)(int))f10)(f14 + f18);
}
