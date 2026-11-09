// from server: 65% by atomic.potato
extern "C" void __cdecl func_007a8ade(void*, int, int, void*);

struct S
{
    void f();
};

void S::f()
{
    func_007a8ade((char*)this + 0xa4, 8, 2, (void*)0x6da340);
}
