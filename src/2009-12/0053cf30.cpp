// from server: 60% by atomic.potato
extern "C" void __cdecl callee(void *, double);

struct S
{
    void __cdecl f(void *, double);
};

void S::f(void *a, double b)
{
    callee(a, b);
}
