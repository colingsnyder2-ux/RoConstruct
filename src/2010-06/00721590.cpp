// from server: 100% by auto
// roc 2010-06 00721590  unit: RBX::UniversalTool  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721590
//
// 00721590  55                   push ebp
// 00721591  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00721595  85ed                 test ebp, ebp
// 00721597  7510                 jne 0x7215a9
// 00721599  8b442408             mov eax, dword ptr [esp + 8]
// 0072159d  8b4808               mov ecx, dword ptr [eax + 8]
// 007215a0  896908               mov dword ptr [ecx + 8], ebp
// 007215a3  83400810             add dword ptr [eax + 8], 0x10
// 007215a7  5d                   pop ebp
// 007215a8  c3                   ret 
// 007215a9  8bc5                 mov eax, ebp
// 007215ab  8d5001               lea edx, [eax + 1]
// 007215ae  8bff                 mov edi, edi
// 007215b0  8a08                 mov cl, byte ptr [eax]
// 007215b2  40                   inc eax
// 007215b3  84c9                 test cl, cl
// 007215b5  75f9                 jne 0x7215b0
// 007215b7  53                   push ebx
// 007215b8  2bc2                 sub eax, edx
// 007215ba  56                   push esi
// 007215bb  8b742410             mov esi, dword ptr [esp + 0x10]
// 007215bf  8bd8                 mov ebx, eax
// 007215c1  8b4610               mov eax, dword ptr [esi + 0x10]
// 007215c4  8b5044               mov edx, dword ptr [eax + 0x44]
// 007215c7  57                   push edi
// 007215c8  3b5040               cmp edx, dword ptr [eax + 0x40]
// 007215cb  7209                 jb 0x7215d6
// 007215cd  56                   push esi
// 007215ce  e88d980500           call 0x77ae60
// 007215d3  83c404               add esp, 4
// 007215d6  8b7e08               mov edi, dword ptr [esi + 8]
// 007215d9  53                   push ebx
// 007215da  55                   push ebp
// 007215db  56                   push esi
// 007215dc  e8ffc70500           call 0x77dde0
// 007215e1  83c40c               add esp, 0xc
// 007215e4  8907                 mov dword ptr [edi], eax
// 007215e6  c7470804000000       mov dword ptr [edi + 8], 4
// 007215ed  83460810             add dword ptr [esi + 8], 0x10
// 007215f1  5f                   pop edi
// 007215f2  5e                   pop esi
// 007215f3  5b                   pop ebx
// 007215f4  5d                   pop ebp
// 007215f5  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
