// from server: 100% by tester
struct S
{
    void f();
};

void S::f()
{
    void **p = *(void ***)((char *)this + 0x0c);
    if (p)
        ((void (__thiscall **)(void *, int))p[0])[1](p, 1);
}
