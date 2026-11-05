// from server: 100% by colin
struct S {
    void f(int a, int b, int c);
};

extern "C" void __stdcall helper(int a, const void* p, int b, int c);

void S::f(int a, int b, int c)
{
    helper(a, (const void*)0x784fc8, b, c);
}
