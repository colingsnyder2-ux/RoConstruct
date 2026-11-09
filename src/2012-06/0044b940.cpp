// from server: 55% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
// roc 2012-06 0044b940  unit: CDeclarationView  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044b940
//
// 0044b940  8b89b0000000         mov ecx, dword ptr [ecx + 0xb0]
// 0044b946  85c9                 test ecx, ecx
// 0044b948  741a                 je 0x44b964
// 0044b94a  8b442404             mov eax, dword ptr [esp + 4]
// 0044b94e  8b505c               mov edx, dword ptr [eax + 0x5c]
// 0044b951  52                   push edx
// 0044b952  e8c9f9ffff           call 0x44b320
// 0044b957  8b442408             mov eax, dword ptr [esp + 8]
// 0044b95b  c70000000000         mov dword ptr [eax], 0
// 0044b961  c20800               ret 8
// 0044b964  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044b968  c70100000000         mov dword ptr [ecx], 0
// 0044b96e  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTHtmlView.cpp (function ?get_accChild@CFormView@@UAEJUtagVARIANT@@PAPAUIDispatch@@@Z)





struct CDeclarationView {
    void f();
};

void CDeclarationView::f() {
    if (*(DWORD*)((char*)this + 0xb0)) {
        DWORD* eax = (DWORD*)*(DWORD*)((char*)this + 4);
        DWORD edx = eax[0x5c / sizeof(DWORD)];
        ((void(__stdcall*)(DWORD))0x44b320)(edx);
        *(DWORD*)*(DWORD*)((char*)this + 8) = 0;
    } else {
        *(DWORD*)*(DWORD*)((char*)this + 8) = 0;
    }
}
