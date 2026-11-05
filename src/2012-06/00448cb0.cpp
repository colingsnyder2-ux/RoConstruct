// from server: 100% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct CMultiPlayerPane {
    void func_00448cb0();
};

void CMultiPlayerPane::func_00448cb0()
{
    *(DWORD*)((char*)this + 0x54) = 0;
    extern void func_0x982ba6();
    func_0x982ba6();
}
