// from server: 100% by auto
// roc 2009-12 007d0d80  unit: RBX::PartDropTool  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0d80
//
// 007d0d80  56                   push esi
// 007d0d81  57                   push edi
// 007d0d82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007d0d86  6a20                 push 0x20
// 007d0d88  6a00                 push 0
// 007d0d8a  6a00                 push 0
// 007d0d8c  57                   push edi
// 007d0d8d  e81e0a0000           call 0x7d17b0
// 007d0d92  8bf0                 mov esi, eax
// 007d0d94  6a0a                 push 0xa
// 007d0d96  56                   push esi
// 007d0d97  57                   push edi
// 007d0d98  e8c3cfffff           call 0x7cdd60
// 007d0d9d  8d4610               lea eax, [esi + 0x10]
// 007d0da0  83c41c               add esp, 0x1c
// 007d0da3  894608               mov dword ptr [esi + 8], eax
// 007d0da6  c7400800000000       mov dword ptr [eax + 8], 0
// 007d0dad  5f                   pop edi
// 007d0dae  8bc6                 mov eax, esi
// 007d0db0  5e                   pop esi
// 007d0db1  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_newupval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
