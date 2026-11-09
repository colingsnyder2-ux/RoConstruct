// from server: 2% by colin
struct CXTPPropertyGridCoolTheme {
    char pad[0x34];
    void* m_pPaintManager;
    void RefreshMetrics(int);
};

struct CObject {
    void* GetSomething(int);
};

extern "C" void* __stdcall sub_668F70();
extern "C" void __stdcall sub_6F9380();

void CXTPPropertyGridCoolTheme::RefreshMetrics(int)
{
    sub_6F9380();
    CObject* p = (CObject*)sub_668F70();
    void* r = p->GetSomething(0xf);
    *(void**)((char*)m_pPaintManager + 0x50) = r;
}
