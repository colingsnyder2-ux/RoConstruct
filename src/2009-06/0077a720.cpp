// from server: 100% by auto
// roc 2009-06 0077a720  unit: CXTPControlTabWorkspace  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a720
//
// 0077a720  8b442404             mov eax, dword ptr [esp + 4]
// 0077a724  85c0                 test eax, eax
// 0077a726  750e                 jne 0x77a736
// 0077a728  50                   push eax
// 0077a729  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0077a72c  50                   push eax
// 0077a72d  ff1508ef8900         call dword ptr [0x89ef08]
// 0077a733  c20400               ret 4
// 0077a736  8b4020               mov eax, dword ptr [eax + 0x20]
// 0077a739  50                   push eax
// 0077a73a  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0077a73d  50                   push eax
// 0077a73e  ff1508ef8900         call dword ptr [0x89ef08]
// 0077a744  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertdialog.cpp (function ?IsChild@CWnd@@QBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertdialog.cpp
