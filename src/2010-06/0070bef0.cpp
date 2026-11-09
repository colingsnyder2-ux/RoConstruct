// from server: 100% by atomic.potato
typedef unsigned int uint32;

extern "C" void __cdecl sub_599a60(void *);

struct S
{
    int unused_00;
    int unused_04;
    int unused_08;
    void *field_0c;
    void f();
};

void S::f()
{
    void *p = field_0c;
    sub_599a60(p);
    if (p)
    {
        void **vptr = *(void ***)((char *)p + 0x18);
        ((void (__thiscall *)(void *, int))vptr[0])((char *)p + 0x18, 1);
    }
}
