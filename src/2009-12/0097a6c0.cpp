// from server: 52% by atomic.potato
extern "C" void __cdecl T_func_0074e420();
extern "C" void __cdecl T_func_007f4929(const void *);

struct S {
    char pad[0xe4];
    void ctor();
};

void S::ctor()
{
    T_func_0074e420();
    *(int *)0xb970f0 = 0x9e4174;
    T_func_007f4929((const void *)0x989270);
}

void func_0097a6c0()
{
    ((S *)0xb970f0)->ctor();
}
