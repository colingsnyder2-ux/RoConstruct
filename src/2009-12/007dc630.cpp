// from server: 100% by auto
// roc 2009-12 007dc630  unit: RBX::GroupDragTool  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc630
//
// 007dc630  8b542410             mov edx, dword ptr [esp + 0x10]
// 007dc634  c1e208               shl edx, 8
// 007dc637  0b54240c             or edx, dword ptr [esp + 0xc]
// 007dc63b  56                   push esi
// 007dc63c  8b742408             mov esi, dword ptr [esp + 8]
// 007dc640  8b460c               mov eax, dword ptr [esi + 0xc]
// 007dc643  8b4808               mov ecx, dword ptr [eax + 8]
// 007dc646  c1e206               shl edx, 6
// 007dc649  0b54240c             or edx, dword ptr [esp + 0xc]
// 007dc64d  51                   push ecx
// 007dc64e  52                   push edx
// 007dc64f  e80cffffff           call 0x7dc560
// 007dc654  83c408               add esp, 8
// 007dc657  5e                   pop esi
// 007dc658  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_codeABx)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
