// from server: 100% by colin
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char*);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);

struct CXTPControlSelector {
    void* m_pVtable;
    void* m_hModule;
    void* m_pGradientFill;
    CXTPControlSelector();
};

CXTPControlSelector::CXTPControlSelector()
{
    m_pVtable = (void*)0x7ceaf8;
    m_pGradientFill = 0;
    m_hModule = LoadLibraryA((const char*)0x7c6d30);
    if (m_hModule != 0)
    {
        m_pGradientFill = GetProcAddress(m_hModule, (const char*)0x7ceae4);
    }
}
