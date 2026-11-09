// from server: 94% by atomic.potato
extern "C" void __stdcall f007f4878(int, int);

struct S
{
    void f();
};

void S::f()
{
    f007f4878(0, 0);
}
