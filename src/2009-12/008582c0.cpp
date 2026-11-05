// from server: 50% by atomic.potato
extern "C" void __cdecl f();

struct S
{
    void f(int, int, int);
};

void S::f(int, int, int)
{
    ::f();
}
