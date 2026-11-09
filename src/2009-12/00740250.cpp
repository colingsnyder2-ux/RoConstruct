// from server: 46% by atomic.potato
struct S
{
    void f(float, float);
};

void S::f(float a, float b)
{
    extern void __stdcall g(float, float, int);
    g(a, b, 2);
}
