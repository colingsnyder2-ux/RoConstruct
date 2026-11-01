// from server: 100% by auto
// roc 2007-03 005b9a80  unit: seg_005b0000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9a80
//
// 005b9a80  56                   push esi
// 005b9a81  8b742408             mov esi, dword ptr [esp + 8]
// 005b9a85  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b9a88  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b9a8b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b9a8e  7209                 jb 0x5b9a99
// 005b9a90  56                   push esi
// 005b9a91  e81afd0300           call 0x5f97b0
// 005b9a96  83c404               add esp, 4
// 005b9a99  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b9a9c  3b4628               cmp eax, dword ptr [esi + 0x28]
// 005b9a9f  7505                 jne 0x5b9aa6
// 005b9aa1  8b4648               mov eax, dword ptr [esi + 0x48]
// 005b9aa4  eb08                 jmp 0x5b9aae
// 005b9aa6  8b5004               mov edx, dword ptr [eax + 4]
// 005b9aa9  8b02                 mov eax, dword ptr [edx]
// 005b9aab  8b400c               mov eax, dword ptr [eax + 0xc]
// 005b9aae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b9ab2  50                   push eax
// 005b9ab3  51                   push ecx
// 005b9ab4  56                   push esi
// 005b9ab5  e8a62d0400           call 0x5fc860
// 005b9aba  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b9abd  8901                 mov dword ptr [ecx], eax
// 005b9abf  83c40c               add esp, 0xc
// 005b9ac2  c7410807000000       mov dword ptr [ecx + 8], 7
// 005b9ac9  83460810             add dword ptr [esi + 8], 0x10
// 005b9acd  83c018               add eax, 0x18
// 005b9ad0  5e                   pop esi
// 005b9ad1  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
