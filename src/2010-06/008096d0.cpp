// from server: 100% by auto
// roc 2010-06 008096d0  unit: CXTPControlTabWorkspace  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008096d0
//
// 008096d0  8b442404             mov eax, dword ptr [esp + 4]
// 008096d4  85c0                 test eax, eax
// 008096d6  750e                 jne 0x8096e6
// 008096d8  50                   push eax
// 008096d9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008096dc  50                   push eax
// 008096dd  ff15acba9e00         call dword ptr [0x9ebaac]
// 008096e3  c20400               ret 4
// 008096e6  8b4020               mov eax, dword ptr [eax + 0x20]
// 008096e9  50                   push eax
// 008096ea  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008096ed  50                   push eax
// 008096ee  ff15acba9e00         call dword ptr [0x9ebaac]
// 008096f4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertdialog.cpp (function ?IsChild@CWnd@@QBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertdialog.cpp
