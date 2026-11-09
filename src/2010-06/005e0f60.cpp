// from server: 93% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall G1_func_00651790(int);

void S::f()
{
    int *p = *(int **)((char *)this + 12);
    int *q = (int *)((char *)p + 0x120);
    int (__thiscall **vtable)(int *);
    vtable = *(int (__thiscall ***) (int *))q;
    int result = vtable[2](q);
    G1_func_00651790(-1);
}
