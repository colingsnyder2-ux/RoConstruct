// from server: 100% by auto
// roc 2007-03 005c4c20  unit: seg_005c0000  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4c20
//
// 005c4c20  83ec08               sub esp, 8
// 005c4c23  53                   push ebx
// 005c4c24  55                   push ebp
// 005c4c25  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c4c29  56                   push esi
// 005c4c2a  8d44240c             lea eax, [esp + 0xc]
// 005c4c2e  50                   push eax
// 005c4c2f  6a01                 push 1
// 005c4c31  55                   push ebp
// 005c4c32  e88959ffff           call 0x5ba5c0
// 005c4c37  8b742418             mov esi, dword ptr [esp + 0x18]
// 005c4c3b  6a01                 push 1
// 005c4c3d  6a02                 push 2
// 005c4c3f  55                   push ebp
// 005c4c40  89442428             mov dword ptr [esp + 0x28], eax
// 005c4c44  e8275bffff           call 0x5ba770
// 005c4c49  83c418               add esp, 0x18
// 005c4c4c  85c0                 test eax, eax
// 005c4c4e  8bd8                 mov ebx, eax
// 005c4c50  7d04                 jge 0x5c4c56
// 005c4c52  8d5c3001             lea ebx, [eax + esi + 1]
// 005c4c56  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005c4c5a  53                   push ebx
// 005c4c5b  6a03                 push 3
// 005c4c5d  55                   push ebp
// 005c4c5e  e80d5bffff           call 0x5ba770
// 005c4c63  83c40c               add esp, 0xc
// 005c4c66  85c0                 test eax, eax
// 005c4c68  7d04                 jge 0x5c4c6e
// 005c4c6a  8d443001             lea eax, [eax + esi + 1]
// 005c4c6e  85db                 test ebx, ebx
// 005c4c70  7f05                 jg 0x5c4c77
// 005c4c72  bb01000000           mov ebx, 1
// 005c4c77  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c4c7b  3bc1                 cmp eax, ecx
// 005c4c7d  7602                 jbe 0x5c4c81
// 005c4c7f  8bc1                 mov eax, ecx
// 005c4c81  3bd8                 cmp ebx, eax
// 005c4c83  7e09                 jle 0x5c4c8e
// 005c4c85  5e                   pop esi
// 005c4c86  5d                   pop ebp
// 005c4c87  33c0                 xor eax, eax
// 005c4c89  5b                   pop ebx
// 005c4c8a  83c408               add esp, 8
// 005c4c8d  c3                   ret 
// 005c4c8e  8bf0                 mov esi, eax
// 005c4c90  2bf3                 sub esi, ebx
// 005c4c92  83c601               add esi, 1
// 005c4c95  8d0c1e               lea ecx, [esi + ebx]
// 005c4c98  3bc8                 cmp ecx, eax
// 005c4c9a  7f0e                 jg 0x5c4caa
// 005c4c9c  68209f7b00           push 0x7b9f20
// 005c4ca1  55                   push ebp
// 005c4ca2  e8a94effff           call 0x5b9b50
// 005c4ca7  83c408               add esp, 8
// 005c4caa  57                   push edi
// 005c4cab  68209f7b00           push 0x7b9f20
// 005c4cb0  56                   push esi
// 005c4cb1  55                   push ebp
// 005c4cb2  e8294fffff           call 0x5b9be0
// 005c4cb7  83c40c               add esp, 0xc
// 005c4cba  33ff                 xor edi, edi
// 005c4cbc  85f6                 test esi, esi
// 005c4cbe  7e1d                 jle 0x5c4cdd
// 005c4cc0  8b542414             mov edx, dword ptr [esp + 0x14]
// 005c4cc4  8d5c13ff             lea ebx, [ebx + edx - 1]
// 005c4cc8  0fb6043b             movzx eax, byte ptr [ebx + edi]
// 005c4ccc  50                   push eax
// 005c4ccd  55                   push ebp
// 005c4cce  e88d43ffff           call 0x5b9060
// 005c4cd3  83c701               add edi, 1
// 005c4cd6  83c408               add esp, 8
// 005c4cd9  3bfe                 cmp edi, esi
// 005c4cdb  7ceb                 jl 0x5c4cc8
// 005c4cdd  5f                   pop edi
// 005c4cde  8bc6                 mov eax, esi
// 005c4ce0  5e                   pop esi
// 005c4ce1  5d                   pop ebp
// 005c4ce2  5b                   pop ebx
// 005c4ce3  83c408               add esp, 8
// 005c4ce6  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_byte)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
