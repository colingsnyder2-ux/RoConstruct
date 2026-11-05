// from server: 100% by auto
// roc 2011-06 00864980  unit: CXTPControlTabWorkspace  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00864980
//
// 00864980  8b442404             mov eax, dword ptr [esp + 4]
// 00864984  85c0                 test eax, eax
// 00864986  750e                 jne 0x864996
// 00864988  50                   push eax
// 00864989  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0086498c  50                   push eax
// 0086498d  ff15081ca400         call dword ptr [0xa41c08]
// 00864993  c20400               ret 4
// 00864996  8b4020               mov eax, dword ptr [eax + 0x20]
// 00864999  50                   push eax
// 0086499a  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0086499d  50                   push eax
// 0086499e  ff15081ca400         call dword ptr [0xa41c08]
// 008649a4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertdialog.cpp (function ?IsChild@CWnd@@QBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertdialog.cpp
