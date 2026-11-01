// from server: 100% by auto
// roc 2007-03 005b9370  unit: seg_005b0000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9370
//
// 005b9370  8b442408             mov eax, dword ptr [esp + 8]
// 005b9374  56                   push esi
// 005b9375  8b742408             mov esi, dword ptr [esp + 8]
// 005b9379  8bce                 mov ecx, esi
// 005b937b  e830f5ffff           call 0x5b88b0
// 005b9380  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b9384  8b10                 mov edx, dword ptr [eax]
// 005b9386  51                   push ecx
// 005b9387  52                   push edx
// 005b9388  e8632a0400           call 0x5fbdf0
// 005b938d  8b10                 mov edx, dword ptr [eax]
// 005b938f  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b9392  8911                 mov dword ptr [ecx], edx
// 005b9394  8b5004               mov edx, dword ptr [eax + 4]
// 005b9397  895104               mov dword ptr [ecx + 4], edx
// 005b939a  8b4008               mov eax, dword ptr [eax + 8]
// 005b939d  83c408               add esp, 8
// 005b93a0  894108               mov dword ptr [ecx + 8], eax
// 005b93a3  83460810             add dword ptr [esi + 8], 0x10
// 005b93a7  5e                   pop esi
// 005b93a8  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
