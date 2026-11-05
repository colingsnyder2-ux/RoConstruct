// from server: 100% by auto
// roc 2010-06 007bdf00  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bdf00
//
// 007bdf00  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bdf04  8b542410             mov edx, dword ptr [esp + 0x10]
// 007bdf08  8b4904               mov ecx, dword ptr [ecx + 4]
// 007bdf0b  50                   push eax
// 007bdf0c  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bdf10  52                   push edx
// 007bdf11  8b542410             mov edx, dword ptr [esp + 0x10]
// 007bdf15  50                   push eax
// 007bdf16  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bdf1a  52                   push edx
// 007bdf1b  50                   push eax
// 007bdf1c  51                   push ecx
// 007bdf1d  ff15b8b99e00         call dword ptr [0x9eb9b8]
// 007bdf23  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
