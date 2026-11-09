// from server: 30% by atomic.potato
struct S
{
    unsigned char pad[0x10c];
    int f();
    void __stdcall g();
};

void __stdcall S::g()
{
}

int S::f()
{
    if (pad[0x10c])
        g();
    return 0;
}
