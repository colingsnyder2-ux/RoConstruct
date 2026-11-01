// from server: 100% by auto
// roc 2007-03 005099e0  unit: seg_00500000  size: 405 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005099e0
//
// 005099e0  53                   push ebx
// 005099e1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005099e5  85db                 test ebx, ebx
// 005099e7  0f8473010000         je 0x509b60
// 005099ed  57                   push edi
// 005099ee  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005099f2  85ff                 test edi, edi
// 005099f4  0f8465010000         je 0x509b5f
// 005099fa  55                   push ebp
// 005099fb  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005099ff  8bc5                 mov eax, ebp
// 00509a01  8d5001               lea edx, [eax + 1]
// 00509a04  8a08                 mov cl, byte ptr [eax]
// 00509a06  83c001               add eax, 1
// 00509a09  84c9                 test cl, cl
// 00509a0b  75f7                 jne 0x509a04
// 00509a0d  56                   push esi
// 00509a0e  2bc2                 sub eax, edx
// 00509a10  8d7001               lea esi, [eax + 1]
// 00509a13  56                   push esi
// 00509a14  53                   push ebx
// 00509a15  e806f60000           call 0x519020
// 00509a1a  83c408               add esp, 8
// 00509a1d  85c0                 test eax, eax
// 00509a1f  8987a0000000         mov dword ptr [edi + 0xa0], eax
// 00509a25  7513                 jne 0x509a3a
// 00509a27  68900c7a00           push 0x7a0c90
// 00509a2c  53                   push ebx
// 00509a2d  e89ee90000           call 0x5183d0
// 00509a32  83c408               add esp, 8
// 00509a35  5e                   pop esi
// 00509a36  5d                   pop ebp
// 00509a37  5f                   pop edi
// 00509a38  5b                   pop ebx
// 00509a39  c3                   ret 
// 00509a3a  56                   push esi
// 00509a3b  55                   push ebp
// 00509a3c  50                   push eax
// 00509a3d  e8a0571100           call 0x61f1e2
// 00509a42  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00509a46  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 00509a4a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00509a4e  8a542434             mov dl, byte ptr [esp + 0x34]
// 00509a52  8987a4000000         mov dword ptr [edi + 0xa4], eax
// 00509a58  8a442438             mov al, byte ptr [esp + 0x38]
// 00509a5c  8887b5000000         mov byte ptr [edi + 0xb5], al
// 00509a62  8bc5                 mov eax, ebp
// 00509a64  83c40c               add esp, 0xc
// 00509a67  898fa8000000         mov dword ptr [edi + 0xa8], ecx
// 00509a6d  8897b4000000         mov byte ptr [edi + 0xb4], dl
// 00509a73  8d7001               lea esi, [eax + 1]
// 00509a76  8a08                 mov cl, byte ptr [eax]
// 00509a78  83c001               add eax, 1
// 00509a7b  84c9                 test cl, cl
// 00509a7d  75f7                 jne 0x509a76
// 00509a7f  2bc6                 sub eax, esi
// 00509a81  8d7001               lea esi, [eax + 1]
// 00509a84  56                   push esi
// 00509a85  53                   push ebx
// 00509a86  e895f50000           call 0x519020
// 00509a8b  83c408               add esp, 8
// 00509a8e  85c0                 test eax, eax
// 00509a90  8987ac000000         mov dword ptr [edi + 0xac], eax
// 00509a96  7513                 jne 0x509aab
// 00509a98  686c0c7a00           push 0x7a0c6c
// 00509a9d  53                   push ebx
// 00509a9e  e82de90000           call 0x5183d0
// 00509aa3  83c408               add esp, 8
// 00509aa6  5e                   pop esi
// 00509aa7  5d                   pop ebp
// 00509aa8  5f                   pop edi
// 00509aa9  5b                   pop ebx
// 00509aaa  c3                   ret 
// 00509aab  56                   push esi
// 00509aac  55                   push ebp
// 00509aad  50                   push eax
// 00509aae  e82f571100           call 0x61f1e2
// 00509ab3  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00509ab7  8d148d04000000       lea edx, [ecx*4 + 4]
// 00509abe  52                   push edx
// 00509abf  53                   push ebx
// 00509ac0  e85bf50000           call 0x519020
// 00509ac5  83c414               add esp, 0x14
// 00509ac8  85c0                 test eax, eax
// 00509aca  8987b0000000         mov dword ptr [edi + 0xb0], eax
// 00509ad0  7513                 jne 0x509ae5
// 00509ad2  68440c7a00           push 0x7a0c44
// 00509ad7  53                   push ebx
// 00509ad8  e8f3e80000           call 0x5183d0
// 00509add  83c408               add esp, 8
// 00509ae0  5e                   pop esi
// 00509ae1  5d                   pop ebp
// 00509ae2  5f                   pop edi
// 00509ae3  5b                   pop ebx
// 00509ae4  c3                   ret 
// 00509ae5  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00509ae9  33f6                 xor esi, esi
// 00509aeb  85c9                 test ecx, ecx
// 00509aed  c7048800000000       mov dword ptr [eax + ecx*4], 0
// 00509af4  7e56                 jle 0x509b4c
// 00509af6  8b442434             mov eax, dword ptr [esp + 0x34]
// 00509afa  8b04b0               mov eax, dword ptr [eax + esi*4]
// 00509afd  8d5001               lea edx, [eax + 1]
// 00509b00  8a08                 mov cl, byte ptr [eax]
// 00509b02  83c001               add eax, 1
// 00509b05  84c9                 test cl, cl
// 00509b07  75f7                 jne 0x509b00
// 00509b09  2bc2                 sub eax, edx
// 00509b0b  8d6801               lea ebp, [eax + 1]
// 00509b0e  55                   push ebp
// 00509b0f  53                   push ebx
// 00509b10  e80bf50000           call 0x519020
// 00509b15  8b8fb0000000         mov ecx, dword ptr [edi + 0xb0]
// 00509b1b  8904b1               mov dword ptr [ecx + esi*4], eax
// 00509b1e  8b97b0000000         mov edx, dword ptr [edi + 0xb0]
// 00509b24  8d04b2               lea eax, [edx + esi*4]
// 00509b27  83c408               add esp, 8
// 00509b2a  833800               cmp dword ptr [eax], 0
// 00509b2d  7433                 je 0x509b62
// 00509b2f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00509b33  8b14b1               mov edx, dword ptr [ecx + esi*4]
// 00509b36  8b00                 mov eax, dword ptr [eax]
// 00509b38  55                   push ebp
// 00509b39  52                   push edx
// 00509b3a  50                   push eax
// 00509b3b  e8a2561100           call 0x61f1e2
// 00509b40  83c601               add esi, 1
// 00509b43  83c40c               add esp, 0xc
// 00509b46  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 00509b4a  7caa                 jl 0x509af6
// 00509b4c  814f0800040000       or dword ptr [edi + 8], 0x400
// 00509b53  818fb800000080000000 or dword ptr [edi + 0xb8], 0x80
// 00509b5d  5e                   pop esi
// 00509b5e  5d                   pop ebp
// 00509b5f  5f                   pop edi
// 00509b60  5b                   pop ebx
// 00509b61  c3                   ret 
// 00509b62  681c0c7a00           push 0x7a0c1c
// 00509b67  53                   push ebx
// 00509b68  e863e80000           call 0x5183d0
// 00509b6d  83c408               add esp, 8
// 00509b70  5e                   pop esi
// 00509b71  5d                   pop ebp
// 00509b72  5f                   pop edi
// 00509b73  5b                   pop ebx
// 00509b74  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_pCAL)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
