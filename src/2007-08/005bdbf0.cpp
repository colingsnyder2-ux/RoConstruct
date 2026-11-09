// from server: 100% by auto
// roc 2007-08 005bdbf0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdbf0
//
// 005bdbf0  55                   push ebp
// 005bdbf1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005bdbf5  85ed                 test ebp, ebp
// 005bdbf7  7510                 jne 0x5bdc09
// 005bdbf9  8b442408             mov eax, dword ptr [esp + 8]
// 005bdbfd  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdc00  896908               mov dword ptr [ecx + 8], ebp
// 005bdc03  83400810             add dword ptr [eax + 8], 0x10
// 005bdc07  5d                   pop ebp
// 005bdc08  c3                   ret 
// 005bdc09  8bc5                 mov eax, ebp
// 005bdc0b  8d5001               lea edx, [eax + 1]
// 005bdc0e  8bff                 mov edi, edi
// 005bdc10  8a08                 mov cl, byte ptr [eax]
// 005bdc12  83c001               add eax, 1
// 005bdc15  84c9                 test cl, cl
// 005bdc17  75f7                 jne 0x5bdc10
// 005bdc19  53                   push ebx
// 005bdc1a  2bc2                 sub eax, edx
// 005bdc1c  56                   push esi
// 005bdc1d  8b742410             mov esi, dword ptr [esp + 0x10]
// 005bdc21  8bd8                 mov ebx, eax
// 005bdc23  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bdc26  8b5044               mov edx, dword ptr [eax + 0x44]
// 005bdc29  3b5040               cmp edx, dword ptr [eax + 0x40]
// 005bdc2c  57                   push edi
// 005bdc2d  7209                 jb 0x5bdc38
// 005bdc2f  56                   push esi
// 005bdc30  e8cb210500           call 0x60fe00
// 005bdc35  83c404               add esp, 4
// 005bdc38  8b7e08               mov edi, dword ptr [esi + 8]
// 005bdc3b  53                   push ebx
// 005bdc3c  55                   push ebp
// 005bdc3d  56                   push esi
// 005bdc3e  e82d510500           call 0x612d70
// 005bdc43  83c40c               add esp, 0xc
// 005bdc46  8907                 mov dword ptr [edi], eax
// 005bdc48  c7470804000000       mov dword ptr [edi + 8], 4
// 005bdc4f  83460810             add dword ptr [esi + 8], 0x10
// 005bdc53  5f                   pop edi
// 005bdc54  5e                   pop esi
// 005bdc55  5b                   pop ebx
// 005bdc56  5d                   pop ebp
// 005bdc57  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
