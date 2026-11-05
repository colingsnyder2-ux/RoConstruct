// from server: 100% by auto
// roc 2011-06 00763330  unit: seg_00760000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00763330
//
// 00763330  56                   push esi
// 00763331  57                   push edi
// 00763332  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00763336  83ff02               cmp edi, 2
// 00763339  7c3d                 jl 0x763378
// 0076333b  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0076333f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00763342  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00763345  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00763348  7209                 jb 0x763353
// 0076334a  56                   push esi
// 0076334b  e8503e0700           call 0x7d71a0
// 00763350  83c404               add esp, 4
// 00763353  8b5608               mov edx, dword ptr [esi + 8]
// 00763356  2b560c               sub edx, dword ptr [esi + 0xc]
// 00763359  c1fa04               sar edx, 4
// 0076335c  4a                   dec edx
// 0076335d  52                   push edx
// 0076335e  57                   push edi
// 0076335f  56                   push esi
// 00763360  e8cb490700           call 0x7d7d30
// 00763365  c1e704               shl edi, 4
// 00763368  83c40c               add esp, 0xc
// 0076336b  b810000000           mov eax, 0x10
// 00763370  2bc7                 sub eax, edi
// 00763372  014608               add dword ptr [esi + 8], eax
// 00763375  5f                   pop edi
// 00763376  5e                   pop esi
// 00763377  c3                   ret 
// 00763378  85ff                 test edi, edi
// 0076337a  7524                 jne 0x7633a0
// 0076337c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00763380  8b7e08               mov edi, dword ptr [esi + 8]
// 00763383  6a00                 push 0
// 00763385  68cabea500           push 0xa5beca
// 0076338a  56                   push esi
// 0076338b  e8906e0700           call 0x7da220
// 00763390  83c40c               add esp, 0xc
// 00763393  8907                 mov dword ptr [edi], eax
// 00763395  c7470804000000       mov dword ptr [edi + 8], 4
// 0076339c  83460810             add dword ptr [esi + 8], 0x10
// 007633a0  5f                   pop edi
// 007633a1  5e                   pop esi
// 007633a2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
