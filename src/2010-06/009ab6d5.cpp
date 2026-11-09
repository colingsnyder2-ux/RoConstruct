// from server: 65% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl func_007a8ade(void *, DWORD, DWORD, DWORD);

struct S
{
    void f();
};

void S::f()
{
    func_007a8ade((char *)this + 0x1b8, 0x0c, 2, 0x7113b0);
}
