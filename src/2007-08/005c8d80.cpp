// from server: 100% by auto
// roc 2007-08 005c8d80  unit: lua_exception  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c8d80
//
// 005c8d80  55                   push ebp
// 005c8d81  56                   push esi
// 005c8d82  57                   push edi
// 005c8d83  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c8d87  6a05                 push 5
// 005c8d89  6a01                 push 1
// 005c8d8b  57                   push edi
// 005c8d8c  e83f65ffff           call 0x5bf2d0
// 005c8d91  6a01                 push 1
// 005c8d93  57                   push edi
// 005c8d94  e8574cffff           call 0x5bd9f0
// 005c8d99  8be8                 mov ebp, eax
// 005c8d9b  55                   push ebp
// 005c8d9c  6a02                 push 2
// 005c8d9e  57                   push edi
// 005c8d9f  e85c67ffff           call 0x5bf500
// 005c8da4  83c420               add esp, 0x20
// 005c8da7  85ed                 test ebp, ebp
// 005c8da9  8bf0                 mov esi, eax
// 005c8dab  7506                 jne 0x5c8db3
// 005c8dad  5f                   pop edi
// 005c8dae  5e                   pop esi
// 005c8daf  33c0                 xor eax, eax
// 005c8db1  5d                   pop ebp
// 005c8db2  c3                   ret 
// 005c8db3  56                   push esi
// 005c8db4  6a01                 push 1
// 005c8db6  57                   push edi
// 005c8db7  e8e450ffff           call 0x5bdea0
// 005c8dbc  83c40c               add esp, 0xc
// 005c8dbf  3bf5                 cmp esi, ebp
// 005c8dc1  7d20                 jge 0x5c8de3
// 005c8dc3  53                   push ebx
// 005c8dc4  8d5e01               lea ebx, [esi + 1]
// 005c8dc7  53                   push ebx
// 005c8dc8  6a01                 push 1
// 005c8dca  57                   push edi
// 005c8dcb  e8d050ffff           call 0x5bdea0
// 005c8dd0  56                   push esi
// 005c8dd1  6a01                 push 1
// 005c8dd3  57                   push edi
// 005c8dd4  e81753ffff           call 0x5be0f0
// 005c8dd9  8bf3                 mov esi, ebx
// 005c8ddb  83c418               add esp, 0x18
// 005c8dde  3bf5                 cmp esi, ebp
// 005c8de0  7ce2                 jl 0x5c8dc4
// 005c8de2  5b                   pop ebx
// 005c8de3  57                   push edi
// 005c8de4  e8674dffff           call 0x5bdb50
// 005c8de9  55                   push ebp
// 005c8dea  6a01                 push 1
// 005c8dec  57                   push edi
// 005c8ded  e8fe52ffff           call 0x5be0f0
// 005c8df2  83c410               add esp, 0x10
// 005c8df5  5f                   pop edi
// 005c8df6  5e                   pop esi
// 005c8df7  b801000000           mov eax, 1
// 005c8dfc  5d                   pop ebp
// 005c8dfd  c3                   ret 
// library lua-5.1.2/ltablib.c (function _tremove)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ltablib.c
