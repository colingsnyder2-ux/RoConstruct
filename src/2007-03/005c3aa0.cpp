// from server: 100% by auto
// roc 2007-03 005c3aa0  unit: seg_005c0000  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3aa0
//
// 005c3aa0  55                   push ebp
// 005c3aa1  56                   push esi
// 005c3aa2  57                   push edi
// 005c3aa3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c3aa7  6a05                 push 5
// 005c3aa9  6a01                 push 1
// 005c3aab  57                   push edi
// 005c3aac  e88f6affff           call 0x5ba540
// 005c3ab1  6a01                 push 1
// 005c3ab3  57                   push edi
// 005c3ab4  e80754ffff           call 0x5b8ec0
// 005c3ab9  8bf0                 mov esi, eax
// 005c3abb  57                   push edi
// 005c3abc  83c601               add esi, 1
// 005c3abf  e88c4fffff           call 0x5b8a50
// 005c3ac4  83c418               add esp, 0x18
// 005c3ac7  83e802               sub eax, 2
// 005c3aca  7465                 je 0x5c3b31
// 005c3acc  83e801               sub eax, 1
// 005c3acf  7412                 je 0x5c3ae3
// 005c3ad1  68cc9b7b00           push 0x7b9bcc
// 005c3ad6  57                   push edi
// 005c3ad7  e87460ffff           call 0x5b9b50
// 005c3adc  83c408               add esp, 8
// 005c3adf  5f                   pop edi
// 005c3ae0  5e                   pop esi
// 005c3ae1  5d                   pop ebp
// 005c3ae2  c3                   ret 
// 005c3ae3  6a02                 push 2
// 005c3ae5  57                   push edi
// 005c3ae6  e8156cffff           call 0x5ba700
// 005c3aeb  8be8                 mov ebp, eax
// 005c3aed  83c408               add esp, 8
// 005c3af0  3bf5                 cmp esi, ebp
// 005c3af2  7d04                 jge 0x5c3af8
// 005c3af4  8bf5                 mov esi, ebp
// 005c3af6  3bf5                 cmp esi, ebp
// 005c3af8  7e39                 jle 0x5c3b33
// 005c3afa  53                   push ebx
// 005c3afb  eb03                 jmp 0x5c3b00
// 005c3afd  8d4900               lea ecx, [ecx]
// 005c3b00  8d5eff               lea ebx, [esi - 1]
// 005c3b03  53                   push ebx
// 005c3b04  6a01                 push 1
// 005c3b06  57                   push edi
// 005c3b07  e86458ffff           call 0x5b9370
// 005c3b0c  56                   push esi
// 005c3b0d  6a01                 push 1
// 005c3b0f  57                   push edi
// 005c3b10  e8ab5affff           call 0x5b95c0
// 005c3b15  8bf3                 mov esi, ebx
// 005c3b17  83c418               add esp, 0x18
// 005c3b1a  3bf5                 cmp esi, ebp
// 005c3b1c  7fe2                 jg 0x5c3b00
// 005c3b1e  5b                   pop ebx
// 005c3b1f  55                   push ebp
// 005c3b20  6a01                 push 1
// 005c3b22  57                   push edi
// 005c3b23  e8985affff           call 0x5b95c0
// 005c3b28  83c40c               add esp, 0xc
// 005c3b2b  5f                   pop edi
// 005c3b2c  5e                   pop esi
// 005c3b2d  33c0                 xor eax, eax
// 005c3b2f  5d                   pop ebp
// 005c3b30  c3                   ret 
// 005c3b31  8bee                 mov ebp, esi
// 005c3b33  55                   push ebp
// 005c3b34  6a01                 push 1
// 005c3b36  57                   push edi
// 005c3b37  e8845affff           call 0x5b95c0
// 005c3b3c  83c40c               add esp, 0xc
// 005c3b3f  5f                   pop edi
// 005c3b40  5e                   pop esi
// 005c3b41  33c0                 xor eax, eax
// 005c3b43  5d                   pop ebp
// 005c3b44  c3                   ret 
// library lua-5.1.1/ltablib.c (function _tinsert)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
