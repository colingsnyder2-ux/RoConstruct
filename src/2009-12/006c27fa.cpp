// from server: 94% by atomic.potato
extern "C" void __stdcall target(int, int);

struct S
{
    void f();
};

void S::f()
{
    target(0, 0);
}
