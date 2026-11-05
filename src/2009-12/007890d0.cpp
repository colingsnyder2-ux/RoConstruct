// from server: 100% by auto
// roc 2009-12 007890d0  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007890d0
//
// 007890d0  56                   push esi
// 007890d1  8b742408             mov esi, dword ptr [esp + 8]
// 007890d5  8b4610               mov eax, dword ptr [esi + 0x10]
// 007890d8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 007890db  57                   push edi
// 007890dc  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 007890df  7209                 jb 0x7890ea
// 007890e1  56                   push esi
// 007890e2  e8294b0400           call 0x7cdc10
// 007890e7  83c404               add esp, 4
// 007890ea  8b542414             mov edx, dword ptr [esp + 0x14]
// 007890ee  8b442410             mov eax, dword ptr [esp + 0x10]
// 007890f2  8b7e08               mov edi, dword ptr [esi + 8]
// 007890f5  52                   push edx
// 007890f6  50                   push eax
// 007890f7  56                   push esi
// 007890f8  e893700400           call 0x7d0190
// 007890fd  83c40c               add esp, 0xc
// 00789100  8907                 mov dword ptr [edi], eax
// 00789102  c7470805000000       mov dword ptr [edi + 8], 5
// 00789109  83460810             add dword ptr [esi + 8], 0x10
// 0078910d  5f                   pop edi
// 0078910e  5e                   pop esi
// 0078910f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
