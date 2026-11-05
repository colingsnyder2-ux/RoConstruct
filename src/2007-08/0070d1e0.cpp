// from server: 100% by colin
struct CXTColorWnd {
    char pad[0x88];
    int field_88;
    CXTColorWnd* construct();
};

extern void __fastcall base_ctor_70c890(CXTColorWnd*);

CXTColorWnd* CXTColorWnd::construct()
{
    base_ctor_70c890(this);
    *(int*)this = 0x7ddd5c;
    field_88 = 0;
    return this;
}
