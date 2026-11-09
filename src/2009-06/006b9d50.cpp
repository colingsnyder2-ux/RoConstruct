// from server: 100% by auto
// roc 2009-06 006b9d50  unit: RBX::UniversalTool  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9d50
//
// 006b9d50  56                   push esi
// 006b9d51  57                   push edi
// 006b9d52  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006b9d56  83ff02               cmp edi, 2
// 006b9d59  7c3d                 jl 0x6b9d98
// 006b9d5b  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b9d5f  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b9d62  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b9d65  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b9d68  7209                 jb 0x6b9d73
// 006b9d6a  56                   push esi
// 006b9d6b  e850fe0200           call 0x6e9bc0
// 006b9d70  83c404               add esp, 4
// 006b9d73  8b5608               mov edx, dword ptr [esi + 8]
// 006b9d76  2b560c               sub edx, dword ptr [esi + 0xc]
// 006b9d79  c1fa04               sar edx, 4
// 006b9d7c  4a                   dec edx
// 006b9d7d  52                   push edx
// 006b9d7e  57                   push edi
// 006b9d7f  56                   push esi
// 006b9d80  e84b090300           call 0x6ea6d0
// 006b9d85  c1e704               shl edi, 4
// 006b9d88  83c40c               add esp, 0xc
// 006b9d8b  b810000000           mov eax, 0x10
// 006b9d90  2bc7                 sub eax, edi
// 006b9d92  014608               add dword ptr [esi + 8], eax
// 006b9d95  5f                   pop edi
// 006b9d96  5e                   pop esi
// 006b9d97  c3                   ret 
// 006b9d98  85ff                 test edi, edi
// 006b9d9a  7524                 jne 0x6b9dc0
// 006b9d9c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b9da0  8b7e08               mov edi, dword ptr [esi + 8]
// 006b9da3  6a00                 push 0
// 006b9da5  6816d28a00           push 0x8ad216
// 006b9daa  56                   push esi
// 006b9dab  e8902d0300           call 0x6ecb40
// 006b9db0  83c40c               add esp, 0xc
// 006b9db3  8907                 mov dword ptr [edi], eax
// 006b9db5  c7470804000000       mov dword ptr [edi + 8], 4
// 006b9dbc  83460810             add dword ptr [esi + 8], 0x10
// 006b9dc0  5f                   pop edi
// 006b9dc1  5e                   pop esi
// 006b9dc2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
