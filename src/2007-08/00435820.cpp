// from server: 1% by colin
struct QTextBrowser {
    void setOpenLinks(bool);
    void setOpenExternalLinks(bool);
};

struct DeclarationView : QTextBrowser {
    char pad0[0xf0];
    void* m_owner;      // 0xf0
    void* m_ownerDiv;   // 0xf4
    void* m_prelim;     // 0xf8
    void* m_deprecated; // 0xfc
    void* m_backend;    // 0x100
    void* m_restricted; // 0x104
    void* m_summary;    // 0x108
    void* m_decl;       // 0x10c
    void updateDeclarationView(void* item);
};

extern "C" void __stdcall VariantInit(void*);
extern "C" void __stdcall VariantClear(void*);

void DeclarationView::updateDeclarationView(void* item)
{
    setOpenLinks(true);
    setOpenExternalLinks(true);
}
