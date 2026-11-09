// from server: 100% by auto
// roc 2010-06 00721f20  unit: RBX::UniversalTool  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721f20
//
// 00721f20  56                   push esi
// 00721f21  57                   push edi
// 00721f22  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00721f26  83ff02               cmp edi, 2
// 00721f29  7c3d                 jl 0x721f68
// 00721f2b  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00721f2f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721f32  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00721f35  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00721f38  7209                 jb 0x721f43
// 00721f3a  56                   push esi
// 00721f3b  e8208f0500           call 0x77ae60
// 00721f40  83c404               add esp, 4
// 00721f43  8b5608               mov edx, dword ptr [esi + 8]
// 00721f46  2b560c               sub edx, dword ptr [esi + 0xc]
// 00721f49  c1fa04               sar edx, 4
// 00721f4c  4a                   dec edx
// 00721f4d  52                   push edx
// 00721f4e  57                   push edi
// 00721f4f  56                   push esi
// 00721f50  e80b9a0500           call 0x77b960
// 00721f55  c1e704               shl edi, 4
// 00721f58  83c40c               add esp, 0xc
// 00721f5b  b810000000           mov eax, 0x10
// 00721f60  2bc7                 sub eax, edi
// 00721f62  014608               add dword ptr [esi + 8], eax
// 00721f65  5f                   pop edi
// 00721f66  5e                   pop esi
// 00721f67  c3                   ret 
// 00721f68  85ff                 test edi, edi
// 00721f6a  7524                 jne 0x721f90
// 00721f6c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00721f70  8b7e08               mov edi, dword ptr [esi + 8]
// 00721f73  6a00                 push 0
// 00721f75  68fe08a000           push 0xa008fe
// 00721f7a  56                   push esi
// 00721f7b  e860be0500           call 0x77dde0
// 00721f80  83c40c               add esp, 0xc
// 00721f83  8907                 mov dword ptr [edi], eax
// 00721f85  c7470804000000       mov dword ptr [edi + 8], 4
// 00721f8c  83460810             add dword ptr [esi + 8], 0x10
// 00721f90  5f                   pop edi
// 00721f91  5e                   pop esi
// 00721f92  c3                   ret 
// library lua-5.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
