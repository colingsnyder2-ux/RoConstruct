// from server: 60% by atomic.potato
extern "C" void __cdecl f0040c080(const char *);

struct S
{
    char padding[0x2a0];
    double value;
    void f(double);
};

void S::f(double x)
{
    if (x >= value)
    {
        value = x;
        f0040c080("SUVW3");
    }
}
