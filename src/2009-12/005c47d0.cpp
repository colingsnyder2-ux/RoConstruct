// from server: 41% by atomic.potato
extern "C" void __stdcall sub_5c3300(int, int, short, short, int);

struct S {
    void __stdcall f(int, int, short, short, int);
};

void __stdcall S::f(int a, int b, short c, short d, int e)
{
    sub_5c3300(a, b, c, d, e);
}
