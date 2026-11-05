// from server: 88% by atomic.potato
struct S {
    void f(float a, float b);
};

extern "C" void __stdcall sub_8f8ef0(S*, float, float);

void S::f(float a, float b)
{
    sub_8f8ef0(this + 0x10, b, a);
}
