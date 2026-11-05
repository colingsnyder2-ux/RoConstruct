// from server: 38% by atomic.potato
struct S {
    int vtable;
    int pad[4];
    int field14;
    int field18;
    void f();
};

void S::f()
{
    vtable = 0xa9114c;
    field14 = 0xa91144;
    field14 = 0xa5bfdc;
    if (field18 != 0) {
        int *p = (int *)field18;
        void (__thiscall *fn)(int *) = (void (__thiscall *)(int *))p[4];
        fn(p);
    }
}
