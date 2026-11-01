// from server: 100% by auto
// roc 2007-03 005b9a00  unit: seg_005b0000  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9a00
//
// 005b9a00  56                   push esi
// 005b9a01  57                   push edi
// 005b9a02  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b9a06  83ff02               cmp edi, 2
// 005b9a09  7c3f                 jl 0x5b9a4a
// 005b9a0b  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b9a0f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b9a12  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b9a15  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b9a18  7209                 jb 0x5b9a23
// 005b9a1a  56                   push esi
// 005b9a1b  e890fd0300           call 0x5f97b0
// 005b9a20  83c404               add esp, 4
// 005b9a23  8b5608               mov edx, dword ptr [esi + 8]
// 005b9a26  2b560c               sub edx, dword ptr [esi + 0xc]
// 005b9a29  c1fa04               sar edx, 4
// 005b9a2c  83ea01               sub edx, 1
// 005b9a2f  52                   push edx
// 005b9a30  57                   push edi
// 005b9a31  56                   push esi
// 005b9a32  e869080400           call 0x5fa2a0
// 005b9a37  c1e704               shl edi, 4
// 005b9a3a  83c40c               add esp, 0xc
// 005b9a3d  b810000000           mov eax, 0x10
// 005b9a42  2bc7                 sub eax, edi
// 005b9a44  014608               add dword ptr [esi + 8], eax
// 005b9a47  5f                   pop edi
// 005b9a48  5e                   pop esi
// 005b9a49  c3                   ret 
// 005b9a4a  85ff                 test edi, edi
// 005b9a4c  7524                 jne 0x5b9a72
// 005b9a4e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b9a52  8b7e08               mov edi, dword ptr [esi + 8]
// 005b9a55  6a00                 push 0
// 005b9a57  68ac497800           push 0x7849ac
// 005b9a5c  56                   push esi
// 005b9a5d  e8be2c0400           call 0x5fc720
// 005b9a62  83c40c               add esp, 0xc
// 005b9a65  8907                 mov dword ptr [edi], eax
// 005b9a67  c7470804000000       mov dword ptr [edi + 8], 4
// 005b9a6e  83460810             add dword ptr [esi + 8], 0x10
// 005b9a72  5f                   pop edi
// 005b9a73  5e                   pop esi
// 005b9a74  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
