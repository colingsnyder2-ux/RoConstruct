// from server: 100% by colin
struct CXTPControlComboBoxGalleryPopupBar
{
    void* vtbl;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    char pad_20[0x28 - 0x20];
    int field_28;

    CXTPControlComboBoxGalleryPopupBar* construct(int);
};

struct Sub20
{
    void method();
};

extern "C" void __stdcall func_0069e7a0();
extern "C" int (__stdcall *func_0077edb8)(int);

extern int dword_007D6004;

CXTPControlComboBoxGalleryPopupBar* CXTPControlComboBoxGalleryPopupBar::construct(int arg)
{
    int (__stdcall *pfn)(int);
    *(int*)this = (int)&dword_007D6004;
    ((Sub20*)((char*)this + 0x20))->method();
    pfn = func_0077edb8;
    field_28 = arg;
    field_04 = pfn(0x15);
    field_08 = pfn(3);
    field_10 = pfn(2);
    field_0c = pfn(0x14);
    field_18 = 0x13;
    field_14 = 0x13;
    field_1c = 0x10;
    return this;
}
