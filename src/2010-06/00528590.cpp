// from server: 39% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_005281f0(void*, int, int, int);

struct ViewG3DFactory
{
    void* Create(int a, int b, int c);
};

void* ViewG3DFactory::Create(int a, int b, int c)
{
    void* p = operator_new(0x60);
    if (p)
        func_005281f0(p, a, b, c);
    return p;
}
