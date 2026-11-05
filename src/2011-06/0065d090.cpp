// from server: 52% by atomic.potato
extern "C" void __stdcall G1_func_00502c30();
extern "C" void __stdcall G1_func_0065bbd0(int, double, const char*, double);

struct S {
    char pad[0xb8];
    int field_b8;
    void f();
};

void S::f()
{
    G1_func_00502c30();
    double d = *(double*)0xa66498;
    d = d * *(double*)0xa66498;
    G1_func_0065bbd0((int)this, d, (const char*)0xa75aec, d);
}
