// from server: 100% by colin
struct CXTPPropertyGridCoolTheme {
    void RefreshMetrics();
    char pad[0x34];
    void* m_pPaintManager;
};

struct CObject {
    void* GetSomething(int n);
};

extern "C" void* __stdcall sub_668F70();
extern "C" void __stdcall sub_6F9380();

void CXTPPropertyGridCoolTheme::RefreshMetrics()
{
    sub_6F9380();
    CObject* p = (CObject*)sub_668F70();
    void* r = p->GetSomething(0xf);
    *(void**)((char*)m_pPaintManager + 0x50) = r;
}
