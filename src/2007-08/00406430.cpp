// from server: 89% by Intel
struct IUnknown {
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

extern "C" void __stdcall sub_4055f0(void* p, IUnknown** pp);

IUnknown* g_pUnk = 0;
void* g_pData = 0;

long __stdcall VCWorkspace_CComObject_Func(void* a1, void* a2, void* a3, IUnknown** ppOut) {
    if (!ppOut) {
        return 0x80004003;
    }

    if (!g_pUnk) {
        sub_4055f0(g_pData, &g_pUnk);
    }

    *ppOut = g_pUnk;

    if (g_pUnk) {
        g_pUnk->AddRef();
    }

    return 0;
}
