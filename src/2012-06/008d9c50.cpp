// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub { void init(); };
struct Players {
    int a;
    Sub sub;
    void g(int* out, int z);
    int* f(int* out, int z);
};
int* Players::f(int* out, int z)
{
    volatile int zero = 0;
    sub.init();
    g(out, z);
    return out;
}