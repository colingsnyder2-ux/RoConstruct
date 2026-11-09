// from server: 65% by atomic.potato
extern "C" void __cdecl func_007a8ade(void*, int, int, const void*);

struct S
{
    void f();
};

void S::f()
{
    func_007a8ade((char*)this + 0x1b8, 0x0c, 2, (const void*)0x7113b0);
}
