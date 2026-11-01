// from server: 100% by auto
// roc 2007-03 005c6ed0  unit: seg_005c0000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6ed0
//
// 005c6ed0  53                   push ebx
// 005c6ed1  57                   push edi
// 005c6ed2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005c6ed6  57                   push edi
// 005c6ed7  e8741bffff           call 0x5b8a50
// 005c6edc  6a01                 push 1
// 005c6ede  57                   push edi
// 005c6edf  8bd8                 mov ebx, eax
// 005c6ee1  e85a1dffff           call 0x5b8c40
// 005c6ee6  83c40c               add esp, 0xc
// 005c6ee9  83f804               cmp eax, 4
// 005c6eec  7527                 jne 0x5c6f15
// 005c6eee  6a00                 push 0
// 005c6ef0  6a01                 push 1
// 005c6ef2  57                   push edi
// 005c6ef3  e8581fffff           call 0x5b8e50
// 005c6ef8  83c40c               add esp, 0xc
// 005c6efb  803823               cmp byte ptr [eax], 0x23
// 005c6efe  7515                 jne 0x5c6f15
// 005c6f00  83c3ff               add ebx, -1
// 005c6f03  53                   push ebx
// 005c6f04  57                   push edi
// 005c6f05  e85621ffff           call 0x5b9060
// 005c6f0a  83c408               add esp, 8
// 005c6f0d  5f                   pop edi
// 005c6f0e  b801000000           mov eax, 1
// 005c6f13  5b                   pop ebx
// 005c6f14  c3                   ret 
// 005c6f15  56                   push esi
// 005c6f16  6a01                 push 1
// 005c6f18  57                   push edi
// 005c6f19  e8e237ffff           call 0x5ba700
// 005c6f1e  8bf0                 mov esi, eax
// 005c6f20  83c408               add esp, 8
// 005c6f23  85f6                 test esi, esi
// 005c6f25  7d04                 jge 0x5c6f2b
// 005c6f27  03f3                 add esi, ebx
// 005c6f29  eb06                 jmp 0x5c6f31
// 005c6f2b  3bf3                 cmp esi, ebx
// 005c6f2d  7e02                 jle 0x5c6f31
// 005c6f2f  8bf3                 mov esi, ebx
// 005c6f31  83fe01               cmp esi, 1
// 005c6f34  7d10                 jge 0x5c6f46
// 005c6f36  6800a57b00           push 0x7ba500
// 005c6f3b  6a01                 push 1
// 005c6f3d  57                   push edi
// 005c6f3e  e8ad34ffff           call 0x5ba3f0
// 005c6f43  83c40c               add esp, 0xc
// 005c6f46  8bc3                 mov eax, ebx
// 005c6f48  2bc6                 sub eax, esi
// 005c6f4a  5e                   pop esi
// 005c6f4b  5f                   pop edi
// 005c6f4c  5b                   pop ebx
// 005c6f4d  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_select)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
