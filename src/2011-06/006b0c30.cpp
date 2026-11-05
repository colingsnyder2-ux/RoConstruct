// from server: 40% by atomic.potato
struct S
{
    void f(int, int);
};

extern "C" void G1_func_004c1670(void *, int);
extern "C" void G1_func_006b0040(void *, int, int);

void S::f(int a, int b)
{
    G1_func_004c1670((char *)this + 4, 1);
    G1_func_006b0040(this, b, a);
}
