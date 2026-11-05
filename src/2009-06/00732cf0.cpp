// from server: 100% by auto
// roc 2009-06 00732cf0  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732cf0
//
// 00732cf0  8b442414             mov eax, dword ptr [esp + 0x14]
// 00732cf4  8b542410             mov edx, dword ptr [esp + 0x10]
// 00732cf8  8b4904               mov ecx, dword ptr [ecx + 4]
// 00732cfb  50                   push eax
// 00732cfc  8b442410             mov eax, dword ptr [esp + 0x10]
// 00732d00  52                   push edx
// 00732d01  8b542410             mov edx, dword ptr [esp + 0x10]
// 00732d05  50                   push eax
// 00732d06  8b442410             mov eax, dword ptr [esp + 0x10]
// 00732d0a  52                   push edx
// 00732d0b  50                   push eax
// 00732d0c  51                   push ecx
// 00732d0d  ff1514ef8900         call dword ptr [0x89ef14]
// 00732d13  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
