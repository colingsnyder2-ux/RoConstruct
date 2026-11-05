// from server: 55% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *field18)(int, int);
    int field1c;
    int field20;
    int f(int, int);
};

int S::f(int a, int b) {
    int *p;
    if (a != 0)
        p = (int *)(a - 0x1c);
    else
        p = 0;
    int idx = field20;
    int *q = (int *)(p[0x138 / 4] + idx);
    int arg = *q + field1c;
    int (__stdcall *fn)(int, int) = field18;
    return fn(arg, b);
}
