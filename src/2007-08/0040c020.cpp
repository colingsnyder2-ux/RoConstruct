// from server: 74% by colin
struct S_func_0040c020 {
    int f(int a, int b, int c, int d);
};

extern "C" int __stdcall sub_004055f0(int);
extern int dword_00881da8;
extern int dword_00881d9c;

int S_func_0040c020::f(int a, int b, int c, int d)
{
    int *p = (int *)d;
    if (p == 0)
        return (int)0x80004003;
    if (dword_00881da8 == 0)
        sub_004055f0(c);
    *p = dword_00881da8;
    int v = dword_00881da8;
    if (v != 0) {
        int (*fn)(int) = *(int (**)(int))v;
        fn(v);
    }
    return 0;
}
