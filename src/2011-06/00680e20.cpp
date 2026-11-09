// from server: 31% by atomic.potato
struct S {
    char pad0[0x10];
    int (*f10)(int);
    int f14;
    int f18;
    char pad1c[0x4];
    int* f20;
    int f();
};

int S::f()
{
    int index = f18;
    int value = f20[index];
    value += f14;
    return f10(value + (int)((char*)f20 + 0x144));
}
