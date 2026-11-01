// from server: 100% by king_originala
extern void __cdecl G1_func_00405aa0(int, int);

struct S
{
    char padding[0x54];
    int field54;

    void G1_func_006a0cc8(int, int, int);
    void func_00456310(int, int, int);
};

void S::func_00456310(int a, int b, int c)
{
    G1_func_006a0cc8(a, b, c);
    if (a)
        G1_func_00405aa0(1, field54);
    else if (b != c)
        G1_func_00405aa0(0, field54);
}
