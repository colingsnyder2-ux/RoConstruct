// from server: 100% by auto
// roc 2008-06 006b52e0  unit: CXTPCommandBar  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006b52e0
//
// 006b52e0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b52e4  8b542410             mov edx, dword ptr [esp + 0x10]
// 006b52e8  8b4904               mov ecx, dword ptr [ecx + 4]
// 006b52eb  50                   push eax
// 006b52ec  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b52f0  52                   push edx
// 006b52f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 006b52f5  50                   push eax
// 006b52f6  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b52fa  52                   push edx
// 006b52fb  50                   push eax
// 006b52fc  51                   push ecx
// 006b52fd  ff15a8208000         call dword ptr [0x8020a8]
// 006b5303  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
