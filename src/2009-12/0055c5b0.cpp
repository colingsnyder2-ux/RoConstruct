// from server: 80% by atomic.potato
struct S
{
    void f(int a, int b);
};

extern void G1_func_00533dd0(void *, int, int);

void S::f(int a, int b)
{
    G1_func_00533dd0((char *)this + 0xe24, a, b);
}
