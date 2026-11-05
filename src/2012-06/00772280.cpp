// from server: 70% by Intel
extern "C" int __cdecl sub_4015a0(const void*, void*);
extern "C" void __cdecl sub_9831f5(const void*);

extern "C" const void* g_772160;
extern "C" void* g_e39abc;
extern "C" unsigned char g_e39ab4;
extern "C" void* g_e39aac;
extern "C" void* g_e39ab0;
extern "C" const void* g_b18d40;

struct FactoryProduct {
    void* method();
};

void* FactoryProduct::method()
{
    sub_4015a0(g_772160, g_e39abc);
    if (g_e39ab4 != 0)
    {
        return g_e39aac;
    }
    g_e39ab4 = 1;
    g_e39aac = 0;
    g_e39ab0 = 0;
    sub_9831f5(g_b18d40);
    return g_e39aac;
}
