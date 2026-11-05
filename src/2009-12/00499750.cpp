// from server: 82% by atomic.potato
struct S
{
    char padding[0x28c];
    void* p;
    void f();
};

extern "C" void func_006cae30(void*);
extern "C" void __cdecl func_007f385a(void*);

void S::f()
{
    void* p = this->p;
    if (p)
    {
        func_006cae30(p);
        func_007f385a(p);
        this->p = 0;
    }
}
