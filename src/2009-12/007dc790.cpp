// from server: 100% by auto
// roc 2009-12 007dc790  unit: RBX::GroupDragTool  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc790
//
// 007dc790  56                   push esi
// 007dc791  8b742408             mov esi, dword ptr [esp + 8]
// 007dc795  8b460c               mov eax, dword ptr [esi + 0xc]
// 007dc798  57                   push edi
// 007dc799  8b7e20               mov edi, dword ptr [esi + 0x20]
// 007dc79c  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 007dc7a3  8b4808               mov ecx, dword ptr [eax + 8]
// 007dc7a6  51                   push ecx
// 007dc7a7  681680ff7f           push 0x7fff8016
// 007dc7ac  e8affdffff           call 0x7dc560
// 007dc7b1  57                   push edi
// 007dc7b2  8d542418             lea edx, [esp + 0x18]
// 007dc7b6  52                   push edx
// 007dc7b7  56                   push esi
// 007dc7b8  89442420             mov dword ptr [esp + 0x20], eax
// 007dc7bc  e80ff9ffff           call 0x7dc0d0
// 007dc7c1  8b442420             mov eax, dword ptr [esp + 0x20]
// 007dc7c5  83c414               add esp, 0x14
// 007dc7c8  5f                   pop edi
// 007dc7c9  5e                   pop esi
// 007dc7ca  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_jump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
