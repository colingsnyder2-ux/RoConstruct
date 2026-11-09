// from server: 91% by Intel
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
    long __thiscall Create(void* pUnkOuter);
};

IUnknown* g_pUnk = 0;
Factory g_factory;

long __stdcall sub_40C020(void* a1, void* a2, void* a3, IUnknown** ppOut)
{
    if (!ppOut)
        return 0x80004003;

    if (!g_pUnk)
    {
        g_factory.Create(a3);
    }

    *ppOut = g_pUnk;

    if (g_pUnk)
    {
        g_pUnk->AddRef(g_pUnk);
    }

    return 0;
}
