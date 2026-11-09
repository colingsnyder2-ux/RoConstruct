// from server: 100% by atomic.potato
struct FactoryProduct
{
    void f();
};

extern "C" void __cdecl G1_func_00685090();

void FactoryProduct::f()
{
    *(int *)this = 0xB8F784;
    *((int *)this + 1) = 0xB8F77C;
    *((int *)this + 6) = 0xB8F770;
    *((int *)this + 7) = 0xB8F764;
    G1_func_00685090();
}
