// from server: 100% by colin
struct CXTPPropertyGridWhidbeyTheme {
    char pad[0x34];
    void* m_pPaintManager;
    char pad2[0x3c - 0x38];
    void* m_pField;
    void Init();
};

struct Helper {
    void* m();
    void* n(int);
};

extern "C" void __stdcall sub_6f9380();
extern "C" Helper* __stdcall sub_668f70();

void CXTPPropertyGridWhidbeyTheme::Init()
{
    sub_6f9380();
    Helper* h1 = sub_668f70();
    void* r1 = h1->n(0xf);
    *(void**)((char*)m_pPaintManager + 0x50) = r1;
    Helper* h2 = sub_668f70();
    void* r2 = h2->n(0x12);
    *(void**)((char*)m_pPaintManager + 0x68) = r2;
    Helper* h3 = sub_668f70();
    void* r3 = h3->n(0x39);
    m_pField = r3;
}
