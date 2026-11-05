// from server: 34% by atomic.potato
extern "C" float __cdecl RBX_VMegaClusterInstance_FactoryProduct_External();

struct S
{
    unsigned char pad[132];
    void* value;
    float f();
};

unsigned char g_flag;

float S::f()
{
    if (g_flag)
        return 0.0f;

    void* p = value;
    return RBX_VMegaClusterInstance_FactoryProduct_External();
}
