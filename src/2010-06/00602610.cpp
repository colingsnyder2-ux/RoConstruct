// from server: 100% by colin
namespace ns_ROCX00000a {
struct S
{
    char pad[12];
    void* field;
    void f();
};

void S::f()
{
    void* p = field;
    if (p)
    {
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = *(Fn *)((char *)*(void **)p + 0x40);
        fn(p, 1);
    }
}
}
