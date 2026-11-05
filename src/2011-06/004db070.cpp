// from server: 43% by atomic.potato
struct S_func_004db070 {
    char pad0[4];
    int field4;
    char pad8[4];
    int fieldC;
    int f(int a1);
};

extern "C" int __cdecl sub_004da5f0(int a1, int a2);

int S_func_004db070::f(int a1)
{
    int r = sub_004da5f0(field4, a1);
    if (r == 0) return 0;
    if (r == 1) return 1;
    if (r == 2) return 2;
    return 0;
}
