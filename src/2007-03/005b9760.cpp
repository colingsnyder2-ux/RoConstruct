// from server: 100% by auto
// roc 2007-03 005b9760  unit: seg_005b0000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9760
//
// 005b9760  8b442408             mov eax, dword ptr [esp + 8]
// 005b9764  56                   push esi
// 005b9765  8b742408             mov esi, dword ptr [esp + 8]
// 005b9769  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b976c  57                   push edi
// 005b976d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005b9771  83c001               add eax, 1
// 005b9774  c1e004               shl eax, 4
// 005b9777  57                   push edi
// 005b9778  2bc8                 sub ecx, eax
// 005b977a  51                   push ecx
// 005b977b  56                   push esi
// 005b977c  e82f6d0000           call 0x5c04b0
// 005b9781  83c40c               add esp, 0xc
// 005b9784  83ffff               cmp edi, -1
// 005b9787  750e                 jne 0x5b9797
// 005b9789  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b978c  8b7608               mov esi, dword ptr [esi + 8]
// 005b978f  3b7008               cmp esi, dword ptr [eax + 8]
// 005b9792  7203                 jb 0x5b9797
// 005b9794  897008               mov dword ptr [eax + 8], esi
// 005b9797  5f                   pop edi
// 005b9798  5e                   pop esi
// 005b9799  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
