// from server: 57% by atomic.potato
extern "C" void __cdecl CallTarget();

struct S
{
    void f();
};

void S::f()
{
    CallTarget();
}
