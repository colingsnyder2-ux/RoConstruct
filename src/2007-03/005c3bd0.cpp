// from server: 100% by auto
// roc 2007-03 005c3bd0  unit: seg_005c0000  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3bd0
//
// 005c3bd0  81ec10020000         sub esp, 0x210
// 005c3bd6  53                   push ebx
// 005c3bd7  55                   push ebp
// 005c3bd8  56                   push esi
// 005c3bd9  8bb42420020000       mov esi, dword ptr [esp + 0x220]
// 005c3be0  57                   push edi
// 005c3be1  8d442410             lea eax, [esp + 0x10]
// 005c3be5  50                   push eax
// 005c3be6  68ac497800           push 0x7849ac
// 005c3beb  6a02                 push 2
// 005c3bed  56                   push esi
// 005c3bee  e82d6affff           call 0x5ba620
// 005c3bf3  6a05                 push 5
// 005c3bf5  6a01                 push 1
// 005c3bf7  56                   push esi
// 005c3bf8  8be8                 mov ebp, eax
// 005c3bfa  e84169ffff           call 0x5ba540
// 005c3bff  6a01                 push 1
// 005c3c01  6a03                 push 3
// 005c3c03  56                   push esi
// 005c3c04  e8676bffff           call 0x5ba770
// 005c3c09  6a04                 push 4
// 005c3c0b  56                   push esi
// 005c3c0c  8bf8                 mov edi, eax
// 005c3c0e  e82d50ffff           call 0x5b8c40
// 005c3c13  83c430               add esp, 0x30
// 005c3c16  85c0                 test eax, eax
// 005c3c18  7f0a                 jg 0x5c3c24
// 005c3c1a  6a01                 push 1
// 005c3c1c  56                   push esi
// 005c3c1d  e89e52ffff           call 0x5b8ec0
// 005c3c22  eb08                 jmp 0x5c3c2c
// 005c3c24  6a04                 push 4
// 005c3c26  56                   push esi
// 005c3c27  e8d46affff           call 0x5ba700
// 005c3c2c  83c408               add esp, 8
// 005c3c2f  8d4c2414             lea ecx, [esp + 0x14]
// 005c3c33  51                   push ecx
// 005c3c34  56                   push esi
// 005c3c35  8bd8                 mov ebx, eax
// 005c3c37  e87463ffff           call 0x5b9fb0
// 005c3c3c  83c408               add esp, 8
// 005c3c3f  3bfb                 cmp edi, ebx
// 005c3c41  7f53                 jg 0x5c3c96
// 005c3c43  57                   push edi
// 005c3c44  6a01                 push 1
// 005c3c46  56                   push esi
// 005c3c47  e82457ffff           call 0x5b9370
// 005c3c4c  6aff                 push -1
// 005c3c4e  56                   push esi
// 005c3c4f  e89c50ffff           call 0x5b8cf0
// 005c3c54  83c414               add esp, 0x14
// 005c3c57  85c0                 test eax, eax
// 005c3c59  7510                 jne 0x5c3c6b
// 005c3c5b  68f49b7b00           push 0x7b9bf4
// 005c3c60  6a01                 push 1
// 005c3c62  56                   push esi
// 005c3c63  e88867ffff           call 0x5ba3f0
// 005c3c68  83c40c               add esp, 0xc
// 005c3c6b  8d542414             lea edx, [esp + 0x14]
// 005c3c6f  52                   push edx
// 005c3c70  e8ab62ffff           call 0x5b9f20
// 005c3c75  83c404               add esp, 4
// 005c3c78  3bfb                 cmp edi, ebx
// 005c3c7a  7413                 je 0x5c3c8f
// 005c3c7c  8b442410             mov eax, dword ptr [esp + 0x10]
// 005c3c80  50                   push eax
// 005c3c81  8d4c2418             lea ecx, [esp + 0x18]
// 005c3c85  55                   push ebp
// 005c3c86  51                   push ecx
// 005c3c87  e8f461ffff           call 0x5b9e80
// 005c3c8c  83c40c               add esp, 0xc
// 005c3c8f  83c701               add edi, 1
// 005c3c92  3bfb                 cmp edi, ebx
// 005c3c94  7ead                 jle 0x5c3c43
// 005c3c96  8d542414             lea edx, [esp + 0x14]
// 005c3c9a  52                   push edx
// 005c3c9b  e84062ffff           call 0x5b9ee0
// 005c3ca0  83c404               add esp, 4
// 005c3ca3  5f                   pop edi
// 005c3ca4  5e                   pop esi
// 005c3ca5  5d                   pop ebp
// 005c3ca6  b801000000           mov eax, 1
// 005c3cab  5b                   pop ebx
// 005c3cac  81c410020000         add esp, 0x210
// 005c3cb2  c3                   ret 
// library lua-5.1.1/ltablib.c (function _tconcat)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
