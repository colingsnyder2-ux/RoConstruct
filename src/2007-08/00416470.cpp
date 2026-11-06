// from server: 81% by Intel
struct IUnknown {
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

extern "C" void __stdcall InitializeCriticalSectionAndSpinCount(void* cs, unsigned int count);

unsigned int** g_ppGlobalPtr = (unsigned int**)0x883164;
void* g_CriticalSection = (void*)0x883158;

long __stdcall GetGlobalPointer(void* unused1, void* unused2, void* unused3, unsigned int** ppOut) {
    if (!ppOut) {
        return 0x80004003;
    }

    if (!*g_ppGlobalPtr) {
        InitializeCriticalSectionAndSpinCount(g_CriticalSection, 0);
    }

    unsigned int* pGlobal = *g_ppGlobalPtr;
    *ppOut = pGlobal;

    if (pGlobal) {
        IUnknown* pUnk = reinterpret_cast<IUnknown*>(pGlobal);
        pUnk->AddRef();
    }

    return 0;
}
