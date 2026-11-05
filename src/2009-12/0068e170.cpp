// from server: 83% by atomic.potato
struct S
{
    char f(int);
};

extern "C" char __cdecl g(int);
extern "C" void h(S *, int);

char S::f(int value)
{
    if (!g(value))
        h(this, value);
    return 0;
}
