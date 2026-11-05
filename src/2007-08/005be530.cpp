// from server: 100% by auto
// roc 2007-08 005be530  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be530
//
// 005be530  56                   push esi
// 005be531  57                   push edi
// 005be532  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005be536  83ff02               cmp edi, 2
// 005be539  7c3f                 jl 0x5be57a
// 005be53b  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005be53f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005be542  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005be545  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005be548  7209                 jb 0x5be553
// 005be54a  56                   push esi
// 005be54b  e8b0180500           call 0x60fe00
// 005be550  83c404               add esp, 4
// 005be553  8b5608               mov edx, dword ptr [esi + 8]
// 005be556  2b560c               sub edx, dword ptr [esi + 0xc]
// 005be559  c1fa04               sar edx, 4
// 005be55c  83ea01               sub edx, 1
// 005be55f  52                   push edx
// 005be560  57                   push edi
// 005be561  56                   push esi
// 005be562  e889230500           call 0x6108f0
// 005be567  c1e704               shl edi, 4
// 005be56a  83c40c               add esp, 0xc
// 005be56d  b810000000           mov eax, 0x10
// 005be572  2bc7                 sub eax, edi
// 005be574  014608               add dword ptr [esi + 8], eax
// 005be577  5f                   pop edi
// 005be578  5e                   pop esi
// 005be579  c3                   ret 
// 005be57a  85ff                 test edi, edi
// 005be57c  7524                 jne 0x5be5a2
// 005be57e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005be582  8b7e08               mov edi, dword ptr [esi + 8]
// 005be585  6a00                 push 0
// 005be587  6854597800           push 0x785954
// 005be58c  56                   push esi
// 005be58d  e8de470500           call 0x612d70
// 005be592  83c40c               add esp, 0xc
// 005be595  8907                 mov dword ptr [edi], eax
// 005be597  c7470804000000       mov dword ptr [edi + 8], 4
// 005be59e  83460810             add dword ptr [esi + 8], 0x10
// 005be5a2  5f                   pop edi
// 005be5a3  5e                   pop esi
// 005be5a4  c3                   ret 
// library lua-5.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
