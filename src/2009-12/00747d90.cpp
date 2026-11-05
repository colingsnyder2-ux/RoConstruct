// from server: 46% by atomic.potato
struct S
{
    void __cdecl f(float, float);
};

void S::f(float a, float b)
{
    ((void (__thiscall *)(S *, float, float))(*(unsigned long *)this))(this, a, b);
}
