// from server: 25% by atomic.potato
extern "C" void __cdecl f();

struct S
{
    int f();
};

int S::f()
{
    f();
    return 0;
}
