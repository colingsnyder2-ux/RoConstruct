// from server: 83% by atomic.potato
struct S {
    int pad0[22];
    int field58;
    int f();
};

int S::f()
{
    int *p = *(int **)(field58 + 0x24);
    int *v = *(int **)p;
    int (__thiscall *fn)(int *, int, int) = (int (__thiscall *)(int *, int, int))v[0x22];
    return fn(p, 0, 1);
}
