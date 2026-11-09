// from server: 100% by auto
// roc 2009-06 006b93c0  unit: RBX::UniversalTool  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b93c0
//
// 006b93c0  55                   push ebp
// 006b93c1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006b93c5  85ed                 test ebp, ebp
// 006b93c7  7510                 jne 0x6b93d9
// 006b93c9  8b442408             mov eax, dword ptr [esp + 8]
// 006b93cd  8b4808               mov ecx, dword ptr [eax + 8]
// 006b93d0  896908               mov dword ptr [ecx + 8], ebp
// 006b93d3  83400810             add dword ptr [eax + 8], 0x10
// 006b93d7  5d                   pop ebp
// 006b93d8  c3                   ret 
// 006b93d9  8bc5                 mov eax, ebp
// 006b93db  8d5001               lea edx, [eax + 1]
// 006b93de  8bff                 mov edi, edi
// 006b93e0  8a08                 mov cl, byte ptr [eax]
// 006b93e2  40                   inc eax
// 006b93e3  84c9                 test cl, cl
// 006b93e5  75f9                 jne 0x6b93e0
// 006b93e7  53                   push ebx
// 006b93e8  2bc2                 sub eax, edx
// 006b93ea  56                   push esi
// 006b93eb  8b742410             mov esi, dword ptr [esp + 0x10]
// 006b93ef  8bd8                 mov ebx, eax
// 006b93f1  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b93f4  8b5044               mov edx, dword ptr [eax + 0x44]
// 006b93f7  57                   push edi
// 006b93f8  3b5040               cmp edx, dword ptr [eax + 0x40]
// 006b93fb  7209                 jb 0x6b9406
// 006b93fd  56                   push esi
// 006b93fe  e8bd070300           call 0x6e9bc0
// 006b9403  83c404               add esp, 4
// 006b9406  8b7e08               mov edi, dword ptr [esi + 8]
// 006b9409  53                   push ebx
// 006b940a  55                   push ebp
// 006b940b  56                   push esi
// 006b940c  e82f370300           call 0x6ecb40
// 006b9411  83c40c               add esp, 0xc
// 006b9414  8907                 mov dword ptr [edi], eax
// 006b9416  c7470804000000       mov dword ptr [edi + 8], 4
// 006b941d  83460810             add dword ptr [esi + 8], 0x10
// 006b9421  5f                   pop edi
// 006b9422  5e                   pop esi
// 006b9423  5b                   pop ebx
// 006b9424  5d                   pop ebp
// 006b9425  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
