// from server: 61% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl func_0080b1d8(void *, DWORD, DWORD, DWORD);

struct S
{
    void f();
};

void S::f()
{
    func_0080b1d8((void *)((char *)this + 0xe8), 0x10, 2, 0x6dc150);
}
