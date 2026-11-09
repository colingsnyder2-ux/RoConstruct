// from server: 100% by auto
// roc 2008-06 00701e10  unit: CXTPControlTabWorkspace  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00701e10
//
// 00701e10  8b442404             mov eax, dword ptr [esp + 4]
// 00701e14  85c0                 test eax, eax
// 00701e16  750e                 jne 0x701e26
// 00701e18  50                   push eax
// 00701e19  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00701e1c  50                   push eax
// 00701e1d  ff15742b8000         call dword ptr [0x802b74]
// 00701e23  c20400               ret 4
// 00701e26  8b4020               mov eax, dword ptr [eax + 0x20]
// 00701e29  50                   push eax
// 00701e2a  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00701e2d  50                   push eax
// 00701e2e  ff15742b8000         call dword ptr [0x802b74]
// 00701e34  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertdialog.cpp (function ?IsChild@CWnd@@QBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertdialog.cpp
