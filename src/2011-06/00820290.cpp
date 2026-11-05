// from server: 100% by auto
// roc 2011-06 00820290  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00820290
//
// 00820290  8b442414             mov eax, dword ptr [esp + 0x14]
// 00820294  8b542410             mov edx, dword ptr [esp + 0x10]
// 00820298  8b4904               mov ecx, dword ptr [ecx + 4]
// 0082029b  50                   push eax
// 0082029c  8b442410             mov eax, dword ptr [esp + 0x10]
// 008202a0  52                   push edx
// 008202a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008202a5  50                   push eax
// 008202a6  8b442410             mov eax, dword ptr [esp + 0x10]
// 008202aa  52                   push edx
// 008202ab  50                   push eax
// 008202ac  51                   push ecx
// 008202ad  ff15d81aa400         call dword ptr [0xa41ad8]
// 008202b3  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
