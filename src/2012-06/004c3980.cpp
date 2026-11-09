// from server: 59% by atomic.potato
extern "C" void __stdcall sub_004c35d0(int, int, int, int, int);

struct S
{
    void f(int, int, int);
};

void S::f(int a, int b, int c)
{
    sub_004c35d0(c, b, c, a, a);
}
