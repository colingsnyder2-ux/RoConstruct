// from server: 100% by auto
// roc 2010-06 007b8af0  unit: CXTPCommandBar  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b8af0
//
// 007b8af0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007b8af4  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b8af8  8b4904               mov ecx, dword ptr [ecx + 4]
// 007b8afb  50                   push eax
// 007b8afc  8b442410             mov eax, dword ptr [esp + 0x10]
// 007b8b00  52                   push edx
// 007b8b01  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b8b05  50                   push eax
// 007b8b06  8b442410             mov eax, dword ptr [esp + 0x10]
// 007b8b0a  52                   push edx
// 007b8b0b  50                   push eax
// 007b8b0c  51                   push ecx
// 007b8b0d  ff1550a19e00         call dword ptr [0x9ea150]
// 007b8b13  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
