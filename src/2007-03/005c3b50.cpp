// from server: 100% by auto
// roc 2007-03 005c3b50  unit: seg_005c0000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3b50
//
// 005c3b50  55                   push ebp
// 005c3b51  56                   push esi
// 005c3b52  57                   push edi
// 005c3b53  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c3b57  6a05                 push 5
// 005c3b59  6a01                 push 1
// 005c3b5b  57                   push edi
// 005c3b5c  e8df69ffff           call 0x5ba540
// 005c3b61  6a01                 push 1
// 005c3b63  57                   push edi
// 005c3b64  e85753ffff           call 0x5b8ec0
// 005c3b69  8be8                 mov ebp, eax
// 005c3b6b  55                   push ebp
// 005c3b6c  6a02                 push 2
// 005c3b6e  57                   push edi
// 005c3b6f  e8fc6bffff           call 0x5ba770
// 005c3b74  83c420               add esp, 0x20
// 005c3b77  85ed                 test ebp, ebp
// 005c3b79  8bf0                 mov esi, eax
// 005c3b7b  7506                 jne 0x5c3b83
// 005c3b7d  5f                   pop edi
// 005c3b7e  5e                   pop esi
// 005c3b7f  33c0                 xor eax, eax
// 005c3b81  5d                   pop ebp
// 005c3b82  c3                   ret 
// 005c3b83  56                   push esi
// 005c3b84  6a01                 push 1
// 005c3b86  57                   push edi
// 005c3b87  e8e457ffff           call 0x5b9370
// 005c3b8c  83c40c               add esp, 0xc
// 005c3b8f  3bf5                 cmp esi, ebp
// 005c3b91  7d20                 jge 0x5c3bb3
// 005c3b93  53                   push ebx
// 005c3b94  8d5e01               lea ebx, [esi + 1]
// 005c3b97  53                   push ebx
// 005c3b98  6a01                 push 1
// 005c3b9a  57                   push edi
// 005c3b9b  e8d057ffff           call 0x5b9370
// 005c3ba0  56                   push esi
// 005c3ba1  6a01                 push 1
// 005c3ba3  57                   push edi
// 005c3ba4  e8175affff           call 0x5b95c0
// 005c3ba9  8bf3                 mov esi, ebx
// 005c3bab  83c418               add esp, 0x18
// 005c3bae  3bf5                 cmp esi, ebp
// 005c3bb0  7ce2                 jl 0x5c3b94
// 005c3bb2  5b                   pop ebx
// 005c3bb3  57                   push edi
// 005c3bb4  e86754ffff           call 0x5b9020
// 005c3bb9  55                   push ebp
// 005c3bba  6a01                 push 1
// 005c3bbc  57                   push edi
// 005c3bbd  e8fe59ffff           call 0x5b95c0
// 005c3bc2  83c410               add esp, 0x10
// 005c3bc5  5f                   pop edi
// 005c3bc6  5e                   pop esi
// 005c3bc7  b801000000           mov eax, 1
// 005c3bcc  5d                   pop ebp
// 005c3bcd  c3                   ret 
// library lua-5.1.1/ltablib.c (function _tremove)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
