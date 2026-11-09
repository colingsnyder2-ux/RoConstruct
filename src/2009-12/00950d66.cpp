// from server: 78% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall func_007f49a4(void *, DWORD, DWORD, DWORD);

struct S_func_00950d66
{
    char pad[0xDC];
    void f();
};

void S_func_00950d66::f()
{
    func_007f49a4((void *)((char *)this + 0xDC), 0x1C, 2, 0x7502B0);
}
