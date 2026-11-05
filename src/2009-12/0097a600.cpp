// from server: 52% by atomic.potato
extern "C" void __cdecl T_func_0074e420();
extern "C" void __cdecl T_func_007f4929(const void *);

struct S {
    char pad[0xcc];
    S();
};

S::S()
{
    T_func_0074e420();
    *(void **)0x00b9729c = (void *)0x009e4174;
    T_func_007f4929((const void *)0x009892f0);
}

void func_0097a600()
{
    S *p = (S *)0x00b9729c;
    p->S::S();
}
