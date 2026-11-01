// from server: 100% by colin
struct CXTPTabClientWnd_CNavigateButtonActiveFiles {
    CXTPTabClientWnd_CNavigateButtonActiveFiles* construct();
    char pad[0x8c];
    double field_90;
};

extern double g_value_78fee8;
extern int g_vtable_7cf7d4;

extern "C" void __stdcall sub_6fe2e0();

CXTPTabClientWnd_CNavigateButtonActiveFiles* CXTPTabClientWnd_CNavigateButtonActiveFiles::construct() {
    sub_6fe2e0();
    field_90 = g_value_78fee8;
    *(int*)this = (int)&g_vtable_7cf7d4;
    *(int*)((char*)this + 0x8c) = 0;
    return this;
}
