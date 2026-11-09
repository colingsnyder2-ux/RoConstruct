// from server: 100% by atomic.potato
struct S
{
    void func_007320f0(int, const void *, const void *, int);
};

extern "C" void __cdecl func_007f4929(const void *);

void func_00978e90()
{
    ((S *)0xb96060)->func_007320f0(160, (const void *)0x9cc0b4, (const void *)0x9bb040, 1);
    func_007f4929((const void *)0x9882b0);
}
