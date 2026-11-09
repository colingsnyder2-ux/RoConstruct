// from server: 59% by atomic.potato
extern "C" void __cdecl T_func_0074e420();
extern "C" void __cdecl T_func_007f4929(const void *);

struct S {
    char pad[0xec];
    S();
};

S *g_obj;

S::S()
{
    T_func_0074e420();
    *(void **)0xb97148 = (void *)0x9e4174;
    T_func_007f4929((const void *)0x9892b0);
}

void func_0097a700()
{
    g_obj = new S;
}
