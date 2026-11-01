// from server: 100% by auto
// roc 2007-03 005b9f20  unit: seg_005b0000  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9f20
//
// 005b9f20  53                   push ebx
// 005b9f21  56                   push esi
// 005b9f22  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b9f26  57                   push edi
// 005b9f27  8b7e08               mov edi, dword ptr [esi + 8]
// 005b9f2a  8d442410             lea eax, [esp + 0x10]
// 005b9f2e  50                   push eax
// 005b9f2f  6aff                 push -1
// 005b9f31  57                   push edi
// 005b9f32  e819efffff           call 0x5b8e50
// 005b9f37  8b0e                 mov ecx, dword ptr [esi]
// 005b9f39  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005b9f3d  8bde                 mov ebx, esi
// 005b9f3f  2bd9                 sub ebx, ecx
// 005b9f41  81c30c020000         add ebx, 0x20c
// 005b9f47  83c40c               add esp, 0xc
// 005b9f4a  3bd3                 cmp edx, ebx
// 005b9f4c  771d                 ja 0x5b9f6b
// 005b9f4e  52                   push edx
// 005b9f4f  50                   push eax
// 005b9f50  51                   push ecx
// 005b9f51  e88c520600           call 0x61f1e2
// 005b9f56  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005b9f5a  010e                 add dword ptr [esi], ecx
// 005b9f5c  6afe                 push -2
// 005b9f5e  57                   push edi
// 005b9f5f  e8fceaffff           call 0x5b8a60
// 005b9f64  83c414               add esp, 0x14
// 005b9f67  5f                   pop edi
// 005b9f68  5e                   pop esi
// 005b9f69  5b                   pop ebx
// 005b9f6a  c3                   ret 
// 005b9f6b  2bce                 sub ecx, esi
// 005b9f6d  83e90c               sub ecx, 0xc
// 005b9f70  741f                 je 0x5b9f91
// 005b9f72  8b5608               mov edx, dword ptr [esi + 8]
// 005b9f75  51                   push ecx
// 005b9f76  8d5e0c               lea ebx, [esi + 0xc]
// 005b9f79  53                   push ebx
// 005b9f7a  52                   push edx
// 005b9f7b  e800f1ffff           call 0x5b9080
// 005b9f80  83460401             add dword ptr [esi + 4], 1
// 005b9f84  6afe                 push -2
// 005b9f86  57                   push edi
// 005b9f87  891e                 mov dword ptr [esi], ebx
// 005b9f89  e872ebffff           call 0x5b8b00
// 005b9f8e  83c414               add esp, 0x14
// 005b9f91  83460401             add dword ptr [esi + 4], 1
// 005b9f95  56                   push esi
// 005b9f96  e825feffff           call 0x5b9dc0
// 005b9f9b  83c404               add esp, 4
// 005b9f9e  5f                   pop edi
// 005b9f9f  5e                   pop esi
// 005b9fa0  5b                   pop ebx
// 005b9fa1  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_addvalue)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
