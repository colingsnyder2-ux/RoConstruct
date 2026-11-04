// from server: 87% by Intel
struct IUnknown
{
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

extern "C" long __stdcall sub_4055f0(void* pUnkOuter, IUnknown** ppUnkInner);

IUnknown* g_pUnk = 0;

long __stdcall sub_40C020(void* a1, void* a2, void* a3, IUnknown** ppOut)
{
    if (!ppOut)
        return 0x80004003;

    if (!g_pUnk)
    {
        sub_4055f0(a3, &g_pUnk);
    }

    *ppOut = g_pUnk;

    if (g_pUnk)
    {
        g_pUnk->AddRef();
    }

    return 0;
}
