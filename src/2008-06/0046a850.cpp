// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct VCSecureHtmlView
{
    void* vtable;
    char pad[0xf0];
    char field_f4;
    VCSecureHtmlView* construct();
};

struct CWebToolbox : VCSecureHtmlView
{
    char pad_f8[4];
    int field_fc;
    CWebToolbox();
};

__forceinline CWebToolbox::CWebToolbox()
{
    construct();
    vtable = (void*)0x81c4f4;
    field_fc = 0;
}

CWebToolbox* create()
{
    return new CWebToolbox;
}
