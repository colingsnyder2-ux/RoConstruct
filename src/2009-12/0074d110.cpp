// from server: 68% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    void f(float, float);
};

extern "C" void __stdcall sub_74cef0(int, int, int, float, float);

void S::f(float x, float y)
{
    sub_74cef0(c, b, (int)this, y, x);
}
