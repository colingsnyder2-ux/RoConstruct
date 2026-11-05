// from server: 100% by auto
// roc 2009-12 00602dc0  unit: seg_00600000  size: 459 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00602dc0
//
// 00602dc0  83ec08               sub esp, 8
// 00602dc3  55                   push ebp
// 00602dc4  57                   push edi
// 00602dc5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00602dc9  85ff                 test edi, edi
// 00602dcb  0f84b2010000         je 0x602f83
// 00602dd1  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00602dd5  85ed                 test ebp, ebp
// 00602dd7  0f84a6010000         je 0x602f83
// 00602ddd  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00602de1  85c9                 test ecx, ecx
// 00602de3  0f849a010000         je 0x602f83
// 00602de9  8b4530               mov eax, dword ptr [ebp + 0x30]
// 00602dec  53                   push ebx
// 00602ded  56                   push esi
// 00602dee  8b7534               mov esi, dword ptr [ebp + 0x34]
// 00602df1  03c1                 add eax, ecx
// 00602df3  3bc6                 cmp eax, esi
// 00602df5  7e7a                 jle 0x602e71
// 00602df7  8b5d38               mov ebx, dword ptr [ebp + 0x38]
// 00602dfa  85db                 test ebx, ebx
// 00602dfc  7448                 je 0x602e46
// 00602dfe  83c008               add eax, 8
// 00602e01  894534               mov dword ptr [ebp + 0x34], eax
// 00602e04  c1e004               shl eax, 4
// 00602e07  50                   push eax
// 00602e08  57                   push edi
// 00602e09  e802df0000           call 0x610d10
// 00602e0e  83c408               add esp, 8
// 00602e11  894538               mov dword ptr [ebp + 0x38], eax
// 00602e14  85c0                 test eax, eax
// 00602e16  7517                 jne 0x602e2f
// 00602e18  53                   push ebx
// 00602e19  57                   push edi
// 00602e1a  e8c1de0000           call 0x610ce0
// 00602e1f  83c408               add esp, 8
// 00602e22  5e                   pop esi
// 00602e23  5b                   pop ebx
// 00602e24  5f                   pop edi
// 00602e25  b801000000           mov eax, 1
// 00602e2a  5d                   pop ebp
// 00602e2b  83c408               add esp, 8
// 00602e2e  c3                   ret 
// 00602e2f  c1e604               shl esi, 4
// 00602e32  56                   push esi
// 00602e33  53                   push ebx
// 00602e34  50                   push eax
// 00602e35  e8ac1e1f00           call 0x7f4ce6
// 00602e3a  53                   push ebx
// 00602e3b  57                   push edi
// 00602e3c  e89fde0000           call 0x610ce0
// 00602e41  83c414               add esp, 0x14
// 00602e44  eb2b                 jmp 0x602e71
// 00602e46  83c108               add ecx, 8
// 00602e49  894d34               mov dword ptr [ebp + 0x34], ecx
// 00602e4c  c1e104               shl ecx, 4
// 00602e4f  51                   push ecx
// 00602e50  57                   push edi
// 00602e51  c7453000000000       mov dword ptr [ebp + 0x30], 0
// 00602e58  e8b3de0000           call 0x610d10
// 00602e5d  83c408               add esp, 8
// 00602e60  894538               mov dword ptr [ebp + 0x38], eax
// 00602e63  85c0                 test eax, eax
// 00602e65  74bb                 je 0x602e22
// 00602e67  818db800000000400000 or dword ptr [ebp + 0xb8], 0x4000
// 00602e71  837c242800           cmp dword ptr [esp + 0x28], 0
// 00602e76  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00602e7e  0f8ef5000000         jle 0x602f79
// 00602e84  8b542424             mov edx, dword ptr [esp + 0x24]
// 00602e88  83c208               add edx, 8
// 00602e8b  89542410             mov dword ptr [esp + 0x10], edx
// 00602e8f  90                   nop 
// 00602e90  8b7530               mov esi, dword ptr [ebp + 0x30]
// 00602e93  8b42fc               mov eax, dword ptr [edx - 4]
// 00602e96  c1e604               shl esi, 4
// 00602e99  037538               add esi, dword ptr [ebp + 0x38]
// 00602e9c  85c0                 test eax, eax
// 00602e9e  0f84bb000000         je 0x602f5f
// 00602ea4  8d5801               lea ebx, [eax + 1]
// 00602ea7  8a08                 mov cl, byte ptr [eax]
// 00602ea9  40                   inc eax
// 00602eaa  84c9                 test cl, cl
// 00602eac  75f9                 jne 0x602ea7
// 00602eae  8b4af8               mov ecx, dword ptr [edx - 8]
// 00602eb1  2bc3                 sub eax, ebx
// 00602eb3  8bd8                 mov ebx, eax
// 00602eb5  85c9                 test ecx, ecx
// 00602eb7  0f8f90000000         jg 0x602f4d
// 00602ebd  8b3a                 mov edi, dword ptr [edx]
// 00602ebf  85ff                 test edi, edi
// 00602ec1  741a                 je 0x602edd
// 00602ec3  803f00               cmp byte ptr [edi], 0
// 00602ec6  7415                 je 0x602edd
// 00602ec8  8d5701               lea edx, [edi + 1]
// 00602ecb  eb03                 jmp 0x602ed0
// 00602ecd  8d4900               lea ecx, [ecx]
// 00602ed0  8a07                 mov al, byte ptr [edi]
// 00602ed2  47                   inc edi
// 00602ed3  84c0                 test al, al
// 00602ed5  75f9                 jne 0x602ed0
// 00602ed7  2bfa                 sub edi, edx
// 00602ed9  890e                 mov dword ptr [esi], ecx
// 00602edb  eb08                 jmp 0x602ee5
// 00602edd  33ff                 xor edi, edi
// 00602edf  c706ffffffff         mov dword ptr [esi], 0xffffffff
// 00602ee5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00602ee9  8d541f04             lea edx, [edi + ebx + 4]
// 00602eed  52                   push edx
// 00602eee  50                   push eax
// 00602eef  e81cde0000           call 0x610d10
// 00602ef4  83c408               add esp, 8
// 00602ef7  894604               mov dword ptr [esi + 4], eax
// 00602efa  85c0                 test eax, eax
// 00602efc  0f8420ffffff         je 0x602e22
// 00602f02  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00602f06  8b51fc               mov edx, dword ptr [ecx - 4]
// 00602f09  53                   push ebx
// 00602f0a  52                   push edx
// 00602f0b  50                   push eax
// 00602f0c  e8d51d1f00           call 0x7f4ce6
// 00602f11  8b4604               mov eax, dword ptr [esi + 4]
// 00602f14  c6040300             mov byte ptr [ebx + eax], 0
// 00602f18  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602f1b  83c40c               add esp, 0xc
// 00602f1e  8d5c0b01             lea ebx, [ebx + ecx + 1]
// 00602f22  895e08               mov dword ptr [esi + 8], ebx
// 00602f25  85ff                 test edi, edi
// 00602f27  7411                 je 0x602f3a
// 00602f29  8b542410             mov edx, dword ptr [esp + 0x10]
// 00602f2d  8b02                 mov eax, dword ptr [edx]
// 00602f2f  57                   push edi
// 00602f30  50                   push eax
// 00602f31  53                   push ebx
// 00602f32  e8af1d1f00           call 0x7f4ce6
// 00602f37  83c40c               add esp, 0xc
// 00602f3a  8b4e08               mov ecx, dword ptr [esi + 8]
// 00602f3d  c6040f00             mov byte ptr [edi + ecx], 0
// 00602f41  897e0c               mov dword ptr [esi + 0xc], edi
// 00602f44  ff4530               inc dword ptr [ebp + 0x30]
// 00602f47  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00602f4b  eb0e                 jmp 0x602f5b
// 00602f4d  68ec369c00           push 0x9c36ec
// 00602f52  57                   push edi
// 00602f53  e8e8d20000           call 0x610240
// 00602f58  83c408               add esp, 8
// 00602f5b  8b542410             mov edx, dword ptr [esp + 0x10]
// 00602f5f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00602f63  40                   inc eax
// 00602f64  83c210               add edx, 0x10
// 00602f67  3b442428             cmp eax, dword ptr [esp + 0x28]
// 00602f6b  89442414             mov dword ptr [esp + 0x14], eax
// 00602f6f  89542410             mov dword ptr [esp + 0x10], edx
// 00602f73  0f8c17ffffff         jl 0x602e90
// 00602f79  5e                   pop esi
// 00602f7a  5b                   pop ebx
// 00602f7b  5f                   pop edi
// 00602f7c  33c0                 xor eax, eax
// 00602f7e  5d                   pop ebp
// 00602f7f  83c408               add esp, 8
// 00602f82  c3                   ret 
// 00602f83  5f                   pop edi
// 00602f84  33c0                 xor eax, eax
// 00602f86  5d                   pop ebp
// 00602f87  83c408               add esp, 8
// 00602f8a  c3                   ret 
// library libpng-1.2.18/pngset.c (function _png_set_text_2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngset.c
