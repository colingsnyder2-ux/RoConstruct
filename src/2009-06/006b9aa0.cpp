// from server: 100% by auto
// roc 2009-06 006b9aa0  unit: RBX::UniversalTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9aa0
//
// 006b9aa0  8b442408             mov eax, dword ptr [esp + 8]
// 006b9aa4  56                   push esi
// 006b9aa5  8b742408             mov esi, dword ptr [esp + 8]
// 006b9aa9  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b9aac  57                   push edi
// 006b9aad  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006b9ab1  40                   inc eax
// 006b9ab2  c1e004               shl eax, 4
// 006b9ab5  57                   push edi
// 006b9ab6  2bc8                 sub ecx, eax
// 006b9ab8  51                   push ecx
// 006b9ab9  56                   push esi
// 006b9aba  e8d19a0000           call 0x6c3590
// 006b9abf  83c40c               add esp, 0xc
// 006b9ac2  83ffff               cmp edi, -1
// 006b9ac5  750e                 jne 0x6b9ad5
// 006b9ac7  8b4614               mov eax, dword ptr [esi + 0x14]
// 006b9aca  8b7608               mov esi, dword ptr [esi + 8]
// 006b9acd  3b7008               cmp esi, dword ptr [eax + 8]
// 006b9ad0  7203                 jb 0x6b9ad5
// 006b9ad2  897008               mov dword ptr [eax + 8], esi
// 006b9ad5  5f                   pop edi
// 006b9ad6  5e                   pop esi
// 006b9ad7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
