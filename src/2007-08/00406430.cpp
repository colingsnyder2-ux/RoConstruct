// from server: 93% by Intel
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD

struct IUnknown
{
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __thiscall AddRef(void* self) = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Factory
{
    IUnknown* pUnk;
    void* pData;
    long __thiscall Create(void* pUnkOuter);
};

Factory g_factory;

long __stdcall sub_406430(void* a1, void* a2, void* a3, IUnknown** ppOut)
{
    if (!ppOut)
        return 0x80004003;

    if (!g_factory.pUnk)
    {
        g_factory.Create(g_factory.pData);
    }

    *ppOut = g_factory.pUnk;

    if (g_factory.pUnk)
    {
        g_factory.pUnk->AddRef(g_factory.pUnk);
    }

    return 0;
}