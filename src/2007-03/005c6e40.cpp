// from server: 100% by auto
// roc 2007-03 005c6e40  unit: seg_005c0000  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6e40
//
// 005c6e40  53                   push ebx
// 005c6e41  55                   push ebp
// 005c6e42  56                   push esi
// 005c6e43  57                   push edi
// 005c6e44  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005c6e48  6a05                 push 5
// 005c6e4a  6a01                 push 1
// 005c6e4c  57                   push edi
// 005c6e4d  e8ee36ffff           call 0x5ba540
// 005c6e52  6a01                 push 1
// 005c6e54  6a02                 push 2
// 005c6e56  57                   push edi
// 005c6e57  e81439ffff           call 0x5ba770
// 005c6e5c  6a03                 push 3
// 005c6e5e  57                   push edi
// 005c6e5f  8bf0                 mov esi, eax
// 005c6e61  e8da1dffff           call 0x5b8c40
// 005c6e66  83c420               add esp, 0x20
// 005c6e69  85c0                 test eax, eax
// 005c6e6b  7f0a                 jg 0x5c6e77
// 005c6e6d  6a01                 push 1
// 005c6e6f  57                   push edi
// 005c6e70  e84b20ffff           call 0x5b8ec0
// 005c6e75  eb08                 jmp 0x5c6e7f
// 005c6e77  6a03                 push 3
// 005c6e79  57                   push edi
// 005c6e7a  e88138ffff           call 0x5ba700
// 005c6e7f  8bd8                 mov ebx, eax
// 005c6e81  8beb                 mov ebp, ebx
// 005c6e83  2bee                 sub ebp, esi
// 005c6e85  83c501               add ebp, 1
// 005c6e88  83c408               add esp, 8
// 005c6e8b  85ed                 test ebp, ebp
// 005c6e8d  7f07                 jg 0x5c6e96
// 005c6e8f  5f                   pop edi
// 005c6e90  5e                   pop esi
// 005c6e91  5d                   pop ebp
// 005c6e92  33c0                 xor eax, eax
// 005c6e94  5b                   pop ebx
// 005c6e95  c3                   ret 
// 005c6e96  68e8a47b00           push 0x7ba4e8
// 005c6e9b  55                   push ebp
// 005c6e9c  57                   push edi
// 005c6e9d  e83e2dffff           call 0x5b9be0
// 005c6ea2  83c40c               add esp, 0xc
// 005c6ea5  3bf3                 cmp esi, ebx
// 005c6ea7  7f1a                 jg 0x5c6ec3
// 005c6ea9  8da42400000000       lea esp, [esp]
// 005c6eb0  56                   push esi
// 005c6eb1  6a01                 push 1
// 005c6eb3  57                   push edi
// 005c6eb4  e8b724ffff           call 0x5b9370
// 005c6eb9  83c601               add esi, 1
// 005c6ebc  83c40c               add esp, 0xc
// 005c6ebf  3bf3                 cmp esi, ebx
// 005c6ec1  7eed                 jle 0x5c6eb0
// 005c6ec3  5f                   pop edi
// 005c6ec4  5e                   pop esi
// 005c6ec5  8bc5                 mov eax, ebp
// 005c6ec7  5d                   pop ebp
// 005c6ec8  5b                   pop ebx
// 005c6ec9  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_unpack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
