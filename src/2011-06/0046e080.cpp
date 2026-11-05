// from server: 100% by atomic.potato
struct CRobloxControlMaterialSelector
{
    char padding[384];
    int materialIndex;
    unsigned char initialized;
    char padding2[3];
    int material;
    void f();
};

extern int *g_materialTable;
extern void G1_func_0080ecc0();

void CRobloxControlMaterialSelector::f()
{
    if (materialIndex != -1)
    {
        material = g_materialTable[materialIndex * 3];
        initialized = 1;
    }
    G1_func_0080ecc0();
}
