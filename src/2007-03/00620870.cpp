// from server: 100% by tester
struct CXTPControlComboBoxPopupBar {
    CXTPControlComboBoxPopupBar* construct();
};

extern "C" void __stdcall sub_67A190();

CXTPControlComboBoxPopupBar* CXTPControlComboBoxPopupBar::construct()
{
    sub_67A190();
    *(int*)((char*)this + 0x0) = 0x7c2894;
    *(int*)((char*)this + 0x54) = 0x7c2884;
    *(int*)((char*)this + 0x5c) = 0x7c2824;
    *(int*)((char*)this + 0x16c) = 1;
    *(int*)((char*)this + 0xbc) = 0;
    return this;
}