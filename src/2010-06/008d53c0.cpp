// from server: 100% by colin
namespace ns_ROCX000018 {
struct S
{
    static void f(void *p);
};

void S::f(void *p)
{
    if (p)
    {
        typedef void (__thiscall *Fn)(void *, int);
        Fn *vtable = *(Fn **)p;
        vtable[50](p, 1);
    }
}
}
