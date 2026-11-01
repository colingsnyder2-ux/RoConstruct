// from server: 100% by auto
// roc 2007-03 005b8ab0  unit: seg_005b0000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8ab0
//
// 005b8ab0  8b442408             mov eax, dword ptr [esp + 8]
// 005b8ab4  56                   push esi
// 005b8ab5  8b742408             mov esi, dword ptr [esp + 8]
// 005b8ab9  8bce                 mov ecx, esi
// 005b8abb  e8f0fdffff           call 0x5b88b0
// 005b8ac0  83c010               add eax, 0x10
// 005b8ac3  3b4608               cmp eax, dword ptr [esi + 8]
// 005b8ac6  7323                 jae 0x5b8aeb
// 005b8ac8  8d48f0               lea ecx, [eax - 0x10]
// 005b8acb  eb03                 jmp 0x5b8ad0
// 005b8acd  8d4900               lea ecx, [ecx]
// 005b8ad0  8b10                 mov edx, dword ptr [eax]
// 005b8ad2  8911                 mov dword ptr [ecx], edx
// 005b8ad4  8b5004               mov edx, dword ptr [eax + 4]
// 005b8ad7  895104               mov dword ptr [ecx + 4], edx
// 005b8ada  8b5118               mov edx, dword ptr [ecx + 0x18]
// 005b8add  895108               mov dword ptr [ecx + 8], edx
// 005b8ae0  83c010               add eax, 0x10
// 005b8ae3  83c110               add ecx, 0x10
// 005b8ae6  3b4608               cmp eax, dword ptr [esi + 8]
// 005b8ae9  72e5                 jb 0x5b8ad0
// 005b8aeb  834608f0             add dword ptr [esi + 8], -0x10
// 005b8aef  5e                   pop esi
// 005b8af0  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
