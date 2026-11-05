// from server: 66% by atomic.potato
struct S
{
    void __cdecl f(float a, float b, void (*p)(S *, float, float));
};

void S::f(float a, float b, void (*p)(S *, float, float))
{
    p(this, a, b);
}
