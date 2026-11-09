// from server: 31% by atomic.potato
extern "C" void __cdecl target();

struct S
{
    int f();
};

int S::f()
{
    target();
    return 0;
}
