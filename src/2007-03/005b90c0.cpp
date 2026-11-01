// from server: 100% by auto
// roc 2007-03 005b90c0  unit: seg_005b0000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b90c0
//
// 005b90c0  55                   push ebp
// 005b90c1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005b90c5  85ed                 test ebp, ebp
// 005b90c7  7510                 jne 0x5b90d9
// 005b90c9  8b442408             mov eax, dword ptr [esp + 8]
// 005b90cd  8b4808               mov ecx, dword ptr [eax + 8]
// 005b90d0  896908               mov dword ptr [ecx + 8], ebp
// 005b90d3  83400810             add dword ptr [eax + 8], 0x10
// 005b90d7  5d                   pop ebp
// 005b90d8  c3                   ret 
// 005b90d9  8bc5                 mov eax, ebp
// 005b90db  8d5001               lea edx, [eax + 1]
// 005b90de  8bff                 mov edi, edi
// 005b90e0  8a08                 mov cl, byte ptr [eax]
// 005b90e2  83c001               add eax, 1
// 005b90e5  84c9                 test cl, cl
// 005b90e7  75f7                 jne 0x5b90e0
// 005b90e9  53                   push ebx
// 005b90ea  2bc2                 sub eax, edx
// 005b90ec  56                   push esi
// 005b90ed  8b742410             mov esi, dword ptr [esp + 0x10]
// 005b90f1  8bd8                 mov ebx, eax
// 005b90f3  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b90f6  8b5044               mov edx, dword ptr [eax + 0x44]
// 005b90f9  3b5040               cmp edx, dword ptr [eax + 0x40]
// 005b90fc  57                   push edi
// 005b90fd  7209                 jb 0x5b9108
// 005b90ff  56                   push esi
// 005b9100  e8ab060400           call 0x5f97b0
// 005b9105  83c404               add esp, 4
// 005b9108  8b7e08               mov edi, dword ptr [esi + 8]
// 005b910b  53                   push ebx
// 005b910c  55                   push ebp
// 005b910d  56                   push esi
// 005b910e  e80d360400           call 0x5fc720
// 005b9113  83c40c               add esp, 0xc
// 005b9116  8907                 mov dword ptr [edi], eax
// 005b9118  c7470804000000       mov dword ptr [edi + 8], 4
// 005b911f  83460810             add dword ptr [esi + 8], 0x10
// 005b9123  5f                   pop edi
// 005b9124  5e                   pop esi
// 005b9125  5b                   pop ebx
// 005b9126  5d                   pop ebp
// 005b9127  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
