// from server: 87% by colin
// roc 2007-08 004124e0  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004124e0

struct S_func_004124e0 {
    int f(int a1, int a2, int a3, int a4);
};

extern int G1_func_004124e0;
extern int G2_func_004124e0;

struct T_func_004055f0 {
    void m(int a1);
};

extern T_func_004055f0 G3_func_004055f0;

int S_func_004124e0::f(int a1, int a2, int a3, int a4)
{
    if (a4 == 0)
        return (int)0x80004003;
    if (G2_func_004124e0 == 0)
        G3_func_004055f0.m(a3);
    *(int*)a4 = G2_func_004124e0;
    int p = G2_func_004124e0;
    if (p != 0)
    {
        int* vtbl = *(int**)p;
        int (__stdcall *fn)(int) = (int (__stdcall *)(int))vtbl[1];
        fn(p);
    }
    return 0;
}
