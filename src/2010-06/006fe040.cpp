// from server: 78% by atomic.potato
struct S
{
    char pad[0xc0];
    double d0;
    double d1;
    double d2;
    double d3;
    void __thiscall f(float, float, float);
};

extern "C" double __cdecl G1_func_006fdf30(double);

void __thiscall S::f(float a, float b, float c)
{
    d0 = a;
    d1 = G1_func_006fdf30(a);
    d2 = a + c;
    d3 = b;
}
