// from server: 100% by colin
struct S {
    void f(int a, int b, int c);
};

extern "C" void __stdcall helper(int, int, int, int);

void S::f(int a, int b, int c)
{
    helper(a, 0x784b88, b, c);
}
