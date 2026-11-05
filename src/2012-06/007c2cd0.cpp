// from server: 60% by atomic.potato
extern "C" void __stdcall RBX_VMegaClusterInstance_FactoryProduct_750de0(int *);

struct FactoryProduct
{
    void __stdcall f();
};

volatile unsigned char g_flag;

void __stdcall FactoryProduct::f()
{
    if (g_flag)
        return;

    int *p = *(int **)((char *)this + 0x84);
    RBX_VMegaClusterInstance_FactoryProduct_750de0(p);
}
