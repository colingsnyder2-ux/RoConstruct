// from server: 56% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void G1_func_007b7e50(S *);

int S::f(int a)
{
    G1_func_007b7e50((S *)((char *)this + 0xa0));
    return 0;
}
