// from server: 100% by auto
// roc 2008-06 00612280  unit: seg_00610000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612280
//
// 00612280  55                   push ebp
// 00612281  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00612285  85ed                 test ebp, ebp
// 00612287  7510                 jne 0x612299
// 00612289  8b442408             mov eax, dword ptr [esp + 8]
// 0061228d  8b4808               mov ecx, dword ptr [eax + 8]
// 00612290  896908               mov dword ptr [ecx + 8], ebp
// 00612293  83400810             add dword ptr [eax + 8], 0x10
// 00612297  5d                   pop ebp
// 00612298  c3                   ret 
// 00612299  8bc5                 mov eax, ebp
// 0061229b  8d5001               lea edx, [eax + 1]
// 0061229e  8bff                 mov edi, edi
// 006122a0  8a08                 mov cl, byte ptr [eax]
// 006122a2  40                   inc eax
// 006122a3  84c9                 test cl, cl
// 006122a5  75f9                 jne 0x6122a0
// 006122a7  53                   push ebx
// 006122a8  2bc2                 sub eax, edx
// 006122aa  56                   push esi
// 006122ab  8b742410             mov esi, dword ptr [esp + 0x10]
// 006122af  8bd8                 mov ebx, eax
// 006122b1  8b4610               mov eax, dword ptr [esi + 0x10]
// 006122b4  8b5044               mov edx, dword ptr [eax + 0x44]
// 006122b7  57                   push edi
// 006122b8  3b5040               cmp edx, dword ptr [eax + 0x40]
// 006122bb  7209                 jb 0x6122c6
// 006122bd  56                   push esi
// 006122be  e8cda00400           call 0x65c390
// 006122c3  83c404               add esp, 4
// 006122c6  8b7e08               mov edi, dword ptr [esi + 8]
// 006122c9  53                   push ebx
// 006122ca  55                   push ebp
// 006122cb  56                   push esi
// 006122cc  e82fd00400           call 0x65f300
// 006122d1  83c40c               add esp, 0xc
// 006122d4  8907                 mov dword ptr [edi], eax
// 006122d6  c7470804000000       mov dword ptr [edi + 8], 4
// 006122dd  83460810             add dword ptr [esi + 8], 0x10
// 006122e1  5f                   pop edi
// 006122e2  5e                   pop esi
// 006122e3  5b                   pop ebx
// 006122e4  5d                   pop ebp
// 006122e5  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
