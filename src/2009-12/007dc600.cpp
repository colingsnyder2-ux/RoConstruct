// from server: 100% by auto
// roc 2009-12 007dc600  unit: RBX::GroupDragTool  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc600
//
// 007dc600  8b542410             mov edx, dword ptr [esp + 0x10]
// 007dc604  c1e209               shl edx, 9
// 007dc607  0b542414             or edx, dword ptr [esp + 0x14]
// 007dc60b  56                   push esi
// 007dc60c  8b742408             mov esi, dword ptr [esp + 8]
// 007dc610  8b460c               mov eax, dword ptr [esi + 0xc]
// 007dc613  8b4808               mov ecx, dword ptr [eax + 8]
// 007dc616  c1e208               shl edx, 8
// 007dc619  0b542410             or edx, dword ptr [esp + 0x10]
// 007dc61d  51                   push ecx
// 007dc61e  c1e206               shl edx, 6
// 007dc621  0b542410             or edx, dword ptr [esp + 0x10]
// 007dc625  52                   push edx
// 007dc626  e835ffffff           call 0x7dc560
// 007dc62b  83c408               add esp, 8
// 007dc62e  5e                   pop esi
// 007dc62f  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_codeABC)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
