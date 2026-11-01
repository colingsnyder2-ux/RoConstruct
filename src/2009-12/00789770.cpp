// from server: 100% by auto
// roc 2009-12 00789770  unit: RBX::UniversalTool  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789770
//
// 00789770  56                   push esi
// 00789771  57                   push edi
// 00789772  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00789776  83ff02               cmp edi, 2
// 00789779  7c3d                 jl 0x7897b8
// 0078977b  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078977f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00789782  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00789785  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00789788  7209                 jb 0x789793
// 0078978a  56                   push esi
// 0078978b  e880440400           call 0x7cdc10
// 00789790  83c404               add esp, 4
// 00789793  8b5608               mov edx, dword ptr [esi + 8]
// 00789796  2b560c               sub edx, dword ptr [esi + 0xc]
// 00789799  c1fa04               sar edx, 4
// 0078979c  4a                   dec edx
// 0078979d  52                   push edx
// 0078979e  57                   push edi
// 0078979f  56                   push esi
// 007897a0  e86b4f0400           call 0x7ce710
// 007897a5  c1e704               shl edi, 4
// 007897a8  83c40c               add esp, 0xc
// 007897ab  b810000000           mov eax, 0x10
// 007897b0  2bc7                 sub eax, edi
// 007897b2  014608               add dword ptr [esi + 8], eax
// 007897b5  5f                   pop edi
// 007897b6  5e                   pop esi
// 007897b7  c3                   ret 
// 007897b8  85ff                 test edi, edi
// 007897ba  7524                 jne 0x7897e0
// 007897bc  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007897c0  8b7e08               mov edi, dword ptr [esi + 8]
// 007897c3  6a00                 push 0
// 007897c5  6856fd9900           push 0x99fd56
// 007897ca  56                   push esi
// 007897cb  e8c0730400           call 0x7d0b90
// 007897d0  83c40c               add esp, 0xc
// 007897d3  8907                 mov dword ptr [edi], eax
// 007897d5  c7470804000000       mov dword ptr [edi + 8], 4
// 007897dc  83460810             add dword ptr [esi + 8], 0x10
// 007897e0  5f                   pop edi
// 007897e1  5e                   pop esi
// 007897e2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
