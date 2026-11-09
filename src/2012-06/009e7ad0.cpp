// roc 2012-06 009e7ad0  unit: CXTPStatusBar  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e7ad0
//
// 009e7ad0  8b442404             mov eax, dword ptr [esp + 4]
// 009e7ad4  50                   push eax
// 009e7ad5  e816ffffff           call 0x9e79f0
// 009e7ada  85c0                 test eax, eax
// 009e7adc  7503                 jne 0x9e7ae1
// 009e7ade  c20400               ret 4
// 009e7ae1  8b4028               mov eax, dword ptr [eax + 0x28]
// 009e7ae4  c20400               ret 4
// copied from an identical function in another client (function ?GetPane@CXTPStatusBar@ns_ROCX000008@@QAEHH@Z)

namespace ns_ROCX000008 {
struct CXTPStatusBar
{
    int GetPane(int nIndex);
};

extern CXTPStatusBar* __stdcall FindStatusBar(int nID);

int CXTPStatusBar::GetPane(int nIndex)
{
    CXTPStatusBar* pBar = FindStatusBar(nIndex);
    if (pBar == 0)
        return 0;
    return *(int*)((char*)pBar + 0x28);
}
}
