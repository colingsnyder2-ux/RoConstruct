// from server: 100% by auto
// roc 2008-06 006ba7b0  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba7b0
//
// 006ba7b0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006ba7b4  8b542410             mov edx, dword ptr [esp + 0x10]
// 006ba7b8  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ba7bb  50                   push eax
// 006ba7bc  8b442410             mov eax, dword ptr [esp + 0x10]
// 006ba7c0  52                   push edx
// 006ba7c1  8b542410             mov edx, dword ptr [esp + 0x10]
// 006ba7c5  50                   push eax
// 006ba7c6  8b442410             mov eax, dword ptr [esp + 0x10]
// 006ba7ca  52                   push edx
// 006ba7cb  50                   push eax
// 006ba7cc  51                   push ecx
// 006ba7cd  ff15802b8000         call dword ptr [0x802b80]
// 006ba7d3  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
