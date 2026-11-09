// from server: 44% by atomic.potato
extern "C" void __stdcall FactoryProductTarget(void);

struct S
{
    void *FactoryProduct();
};

volatile unsigned char g_flag;

void *S::FactoryProduct()
{
    if (g_flag)
        return 0;

    void *p = *(void **)((char *)this + 0x84);
    void *v = *(void **)p;
    FactoryProductTarget();
    return (char *)v + (unsigned long)this + 0x84;
}
