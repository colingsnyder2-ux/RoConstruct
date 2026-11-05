// from server: 47% by atomic.potato
extern "C" void __cdecl T_func_0074a320();
extern "C" void __cdecl T_func_007f4929(const void *);

struct S {
    char pad[0xcc];
    S();
};

S::S()
{
    T_func_0074a320();
    *(void **)0x00b97098 = (void *)0x009e3e00;
    T_func_007f4929((const void *)0x009890f0);
}
