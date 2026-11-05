// from server: 63% by atomic.potato
extern "C" void __cdecl T_func_00983270(void *, int, int, const void *);

struct S
{
    void f();
};

void S::f()
{
    T_func_00983270((char *)this + 0x34, 0x10, 4, (const void *)0x5047b0);
}
