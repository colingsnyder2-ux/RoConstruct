// from server: 100% by auto
// roc 2009-12 00788de0  unit: RBX::UniversalTool  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788de0
//
// 00788de0  55                   push ebp
// 00788de1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00788de5  85ed                 test ebp, ebp
// 00788de7  7510                 jne 0x788df9
// 00788de9  8b442408             mov eax, dword ptr [esp + 8]
// 00788ded  8b4808               mov ecx, dword ptr [eax + 8]
// 00788df0  896908               mov dword ptr [ecx + 8], ebp
// 00788df3  83400810             add dword ptr [eax + 8], 0x10
// 00788df7  5d                   pop ebp
// 00788df8  c3                   ret 
// 00788df9  8bc5                 mov eax, ebp
// 00788dfb  8d5001               lea edx, [eax + 1]
// 00788dfe  8bff                 mov edi, edi
// 00788e00  8a08                 mov cl, byte ptr [eax]
// 00788e02  40                   inc eax
// 00788e03  84c9                 test cl, cl
// 00788e05  75f9                 jne 0x788e00
// 00788e07  53                   push ebx
// 00788e08  2bc2                 sub eax, edx
// 00788e0a  56                   push esi
// 00788e0b  8b742410             mov esi, dword ptr [esp + 0x10]
// 00788e0f  8bd8                 mov ebx, eax
// 00788e11  8b4610               mov eax, dword ptr [esi + 0x10]
// 00788e14  8b5044               mov edx, dword ptr [eax + 0x44]
// 00788e17  57                   push edi
// 00788e18  3b5040               cmp edx, dword ptr [eax + 0x40]
// 00788e1b  7209                 jb 0x788e26
// 00788e1d  56                   push esi
// 00788e1e  e8ed4d0400           call 0x7cdc10
// 00788e23  83c404               add esp, 4
// 00788e26  8b7e08               mov edi, dword ptr [esi + 8]
// 00788e29  53                   push ebx
// 00788e2a  55                   push ebp
// 00788e2b  56                   push esi
// 00788e2c  e85f7d0400           call 0x7d0b90
// 00788e31  83c40c               add esp, 0xc
// 00788e34  8907                 mov dword ptr [edi], eax
// 00788e36  c7470804000000       mov dword ptr [edi + 8], 4
// 00788e3d  83460810             add dword ptr [esi + 8], 0x10
// 00788e41  5f                   pop edi
// 00788e42  5e                   pop esi
// 00788e43  5b                   pop ebx
// 00788e44  5d                   pop ebp
// 00788e45  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
