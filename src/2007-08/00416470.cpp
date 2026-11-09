// from server: 87% by Intel
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD

struct IUnknown
{
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef(void* self) = 0;
    virtual unsigned long __stdcall Release(void* self) = 0;
};

struct Creator
{
    char pad[0xc];
    IUnknown* pUnk;
    long Create(void* pOuter);
};

Creator g_creator;

long __stdcall sub_416470(void* a1, void* a2, void* a3, IUnknown** ppOut)
{
    if (!ppOut)
        return 0x80004003;

    long result = 0;

    if (!g_creator.pUnk)
        g_creator.Create(a3);

    *ppOut = g_creator.pUnk;

    if (g_creator.pUnk)
        g_creator.pUnk->AddRef(g_creator.pUnk);

    return result;
}
