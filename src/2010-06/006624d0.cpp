// from server: 53% by atomic.potato
struct S {
    int field8;
    int fieldC;
    int f();
};

extern "C" int G1_func_00661fd0(S *, int *);

int S::f()
{
    int *p = field8 ? (int *)(field8 + 0x1c) : 0;
    return G1_func_00661fd0((S *)fieldC, p);
}
