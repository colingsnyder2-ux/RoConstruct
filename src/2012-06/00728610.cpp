// from server: 65% by atomic.potato
struct S {
    char pad0[0x30];
    int (__stdcall *fn30)(int, int);
    int field34;
    int field38;
    char pad3c[0x84 - 0x3c];
    int field84;
    int method(int, int);
};

extern "C" int __stdcall G1_func_00534590(int, int, int);

int S::method(int a, int b)
{
    char ok = (char)G1_func_00534590(b, (int)(this->pad3c), 0);
    int *p = (int *)a;
    if (p)
        p = (int *)((char *)p - 0x1c);
    else
        p = 0;
    int idx = *(int *)((char *)p + 0x84);
    int off = *(int *)(idx + this->field38);
    int base = off + (int)p;
    int arg = *(int *)(base + this->field34 + 0x84);
    return this->fn30(arg, b);
}
