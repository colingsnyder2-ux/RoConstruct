// from server: 100% by atomic.potato
struct S
{
    double f();
    char pad[0xa0];
    double member;
};

extern "C" S* __cdecl callee();

double S::f()
{
    return callee()->member;
}
