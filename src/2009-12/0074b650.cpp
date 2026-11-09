// from server: 38% by atomic.potato
extern "C" void __cdecl unknown();

struct S
{
    int f();
};

int S::f()
{
    unknown();
    return 0;
}
