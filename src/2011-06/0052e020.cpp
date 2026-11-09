// from server: 94% by atomic.potato
struct S
{
    char pad0[0x20];
    long long value;
    void f(int a, int b);
};

extern "C" long long __stdcall function_0080b2b0(int, int, int, int);

void S::f(int a, int b)
{
    this->value = function_0080b2b0(b, a, 1000, 0);
}
