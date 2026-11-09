// from server: 100% by colin
struct CXTPControlComboBoxPopupBar {
    CXTPControlComboBoxPopupBar* construct();
};

extern "C" void __stdcall sub_67A190();

CXTPControlComboBoxPopupBar* CXTPControlComboBoxPopupBar::construct()
{
    sub_67A190();
    *(int*)((char*)this + 0x00) = 0x7c5774;
    *(int*)((char*)this + 0x54) = 0x7c5764;
    *(int*)((char*)this + 0x5c) = 0x7c5704;
    *(int*)((char*)this + 0xbc) = 1;
    *(int*)((char*)this + 0xc0) = 0;
    return this;
}
