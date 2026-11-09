// from server: 100% by auto
// roc 2009-12 007d3880  unit: seg_007d0000  size: 550 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3880
//
// 007d3880  83ec1c               sub esp, 0x1c
// 007d3883  53                   push ebx
// 007d3884  55                   push ebp
// 007d3885  8b6f30               mov ebp, dword ptr [edi + 0x30]
// 007d3888  8b4524               mov eax, dword ptr [ebp + 0x24]
// 007d388b  56                   push esi
// 007d388c  6a0b                 push 0xb
// 007d388e  68ecef9e00           push 0x9eefec
// 007d3893  57                   push edi
// 007d3894  89442418             mov dword ptr [esp + 0x18], eax
// 007d3898  e8c31a0000           call 0x7d5360
// 007d389d  8b7730               mov esi, dword ptr [edi + 0x30]
// 007d38a0  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d38a4  41                   inc ecx
// 007d38a5  83c40c               add esp, 0xc
// 007d38a8  81f9c8000000         cmp ecx, 0xc8
// 007d38ae  8bd8                 mov ebx, eax
// 007d38b0  7e0f                 jle 0x7d38c1
// 007d38b2  b974ee9e00           mov ecx, 0x9eee74
// 007d38b7  bac8000000           mov edx, 0xc8
// 007d38bc  e8cfdfffff           call 0x7d1890
// 007d38c1  53                   push ebx
// 007d38c2  57                   push edi
// 007d38c3  e808e1ffff           call 0x7d19d0
// 007d38c8  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d38cc  6a0b                 push 0xb
// 007d38ce  68e0ef9e00           push 0x9eefe0
// 007d38d3  57                   push edi
// 007d38d4  66898456ac000000     mov word ptr [esi + edx*2 + 0xac], ax
// 007d38dc  e87f1a0000           call 0x7d5360
// 007d38e1  8b7730               mov esi, dword ptr [edi + 0x30]
// 007d38e4  8bd8                 mov ebx, eax
// 007d38e6  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 007d38ea  83c002               add eax, 2
// 007d38ed  83c414               add esp, 0x14
// 007d38f0  3dc8000000           cmp eax, 0xc8
// 007d38f5  7e0f                 jle 0x7d3906
// 007d38f7  b974ee9e00           mov ecx, 0x9eee74
// 007d38fc  bac8000000           mov edx, 0xc8
// 007d3901  e88adfffff           call 0x7d1890
// 007d3906  53                   push ebx
// 007d3907  57                   push edi
// 007d3908  e8c3e0ffff           call 0x7d19d0
// 007d390d  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3911  6a0a                 push 0xa
// 007d3913  68d4ef9e00           push 0x9eefd4
// 007d3918  57                   push edi
// 007d3919  6689844eae000000     mov word ptr [esi + ecx*2 + 0xae], ax
// 007d3921  e83a1a0000           call 0x7d5360
// 007d3926  8b7730               mov esi, dword ptr [edi + 0x30]
// 007d3929  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d392d  83c203               add edx, 3
// 007d3930  83c414               add esp, 0x14
// 007d3933  81fac8000000         cmp edx, 0xc8
// 007d3939  8bd8                 mov ebx, eax
// 007d393b  7e0f                 jle 0x7d394c
// 007d393d  b974ee9e00           mov ecx, 0x9eee74
// 007d3942  bac8000000           mov edx, 0xc8
// 007d3947  e844dfffff           call 0x7d1890
// 007d394c  53                   push ebx
// 007d394d  57                   push edi
// 007d394e  e87de0ffff           call 0x7d19d0
// 007d3953  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3957  6689844eb0000000     mov word ptr [esi + ecx*2 + 0xb0], ax
// 007d395f  8b7730               mov esi, dword ptr [edi + 0x30]
// 007d3962  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d3966  83c204               add edx, 4
// 007d3969  83c408               add esp, 8
// 007d396c  81fac8000000         cmp edx, 0xc8
// 007d3972  7e0f                 jle 0x7d3983
// 007d3974  b974ee9e00           mov ecx, 0x9eee74
// 007d3979  bac8000000           mov edx, 0xc8
// 007d397e  e80ddfffff           call 0x7d1890
// 007d3983  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007d3987  50                   push eax
// 007d3988  57                   push edi
// 007d3989  e842e0ffff           call 0x7d19d0
// 007d398e  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3992  83c408               add esp, 8
// 007d3995  6689844eb2000000     mov word ptr [esi + ecx*2 + 0xb2], ax
// 007d399d  837f103d             cmp dword ptr [edi + 0x10], 0x3d
// 007d39a1  7421                 je 0x7d39c4
// 007d39a3  6a3d                 push 0x3d
// 007d39a5  57                   push edi
// 007d39a6  e895180000           call 0x7d5240
// 007d39ab  8b5734               mov edx, dword ptr [edi + 0x34]
// 007d39ae  50                   push eax
// 007d39af  68d0ed9e00           push 0x9eedd0
// 007d39b4  52                   push edx
// 007d39b5  e8c66bfcff           call 0x79a580
// 007d39ba  50                   push eax
// 007d39bb  57                   push edi
// 007d39bc  e87f190000           call 0x7d5340
// 007d39c1  83c41c               add esp, 0x1c
// 007d39c4  57                   push edi
// 007d39c5  e8662d0000           call 0x7d6730
// 007d39ca  6a00                 push 0
// 007d39cc  8d442418             lea eax, [esp + 0x18]
// 007d39d0  50                   push eax
// 007d39d1  57                   push edi
// 007d39d2  e8d9f6ffff           call 0x7d30b0
// 007d39d7  8b5730               mov edx, dword ptr [edi + 0x30]
// 007d39da  8d4c2420             lea ecx, [esp + 0x20]
// 007d39de  51                   push ecx
// 007d39df  52                   push edx
// 007d39e0  e82b920000           call 0x7dcc10
// 007d39e5  be2c000000           mov esi, 0x2c
// 007d39ea  83c418               add esp, 0x18
// 007d39ed  397710               cmp dword ptr [edi + 0x10], esi
// 007d39f0  7420                 je 0x7d3a12
// 007d39f2  56                   push esi
// 007d39f3  57                   push edi
// 007d39f4  e847180000           call 0x7d5240
// 007d39f9  50                   push eax
// 007d39fa  8b4734               mov eax, dword ptr [edi + 0x34]
// 007d39fd  68d0ed9e00           push 0x9eedd0
// 007d3a02  50                   push eax
// 007d3a03  e8786bfcff           call 0x79a580
// 007d3a08  50                   push eax
// 007d3a09  57                   push edi
// 007d3a0a  e831190000           call 0x7d5340
// 007d3a0f  83c41c               add esp, 0x1c
// 007d3a12  57                   push edi
// 007d3a13  e8182d0000           call 0x7d6730
// 007d3a18  6a00                 push 0
// 007d3a1a  8d4c2418             lea ecx, [esp + 0x18]
// 007d3a1e  51                   push ecx
// 007d3a1f  57                   push edi
// 007d3a20  e88bf6ffff           call 0x7d30b0
// 007d3a25  8b4730               mov eax, dword ptr [edi + 0x30]
// 007d3a28  8d542420             lea edx, [esp + 0x20]
// 007d3a2c  52                   push edx
// 007d3a2d  50                   push eax
// 007d3a2e  e8dd910000           call 0x7dcc10
// 007d3a33  83c418               add esp, 0x18
// 007d3a36  397710               cmp dword ptr [edi + 0x10], esi
// 007d3a39  7526                 jne 0x7d3a61
// 007d3a3b  57                   push edi
// 007d3a3c  e8ef2c0000           call 0x7d6730
// 007d3a41  6a00                 push 0
// 007d3a43  8d4c2418             lea ecx, [esp + 0x18]
// 007d3a47  51                   push ecx
// 007d3a48  57                   push edi
// 007d3a49  e862f6ffff           call 0x7d30b0
// 007d3a4e  8b4730               mov eax, dword ptr [edi + 0x30]
// 007d3a51  8d542420             lea edx, [esp + 0x20]
// 007d3a55  52                   push edx
// 007d3a56  50                   push eax
// 007d3a57  e8b4910000           call 0x7dcc10
// 007d3a5c  83c418               add esp, 0x18
// 007d3a5f  eb26                 jmp 0x7d3a87
// 007d3a61  d9e8                 fld1 
// 007d3a63  83ec08               sub esp, 8
// 007d3a66  dd1c24               fstp qword ptr [esp]
// 007d3a69  55                   push ebp
// 007d3a6a  e861880000           call 0x7dc2d0
// 007d3a6f  8b4d24               mov ecx, dword ptr [ebp + 0x24]
// 007d3a72  50                   push eax
// 007d3a73  51                   push ecx
// 007d3a74  6a01                 push 1
// 007d3a76  55                   push ebp
// 007d3a77  e8b48b0000           call 0x7dc630
// 007d3a7c  6a01                 push 1
// 007d3a7e  55                   push ebp
// 007d3a7f  e8dc860000           call 0x7dc160
// 007d3a84  83c424               add esp, 0x24
// 007d3a87  8b542430             mov edx, dword ptr [esp + 0x30]
// 007d3a8b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d3a8f  6a01                 push 1
// 007d3a91  6a01                 push 1
// 007d3a93  52                   push edx
// 007d3a94  50                   push eax
// 007d3a95  8bc7                 mov eax, edi
// 007d3a97  e844fcffff           call 0x7d36e0
// 007d3a9c  83c410               add esp, 0x10
// 007d3a9f  5e                   pop esi
// 007d3aa0  5d                   pop ebp
// 007d3aa1  5b                   pop ebx
// 007d3aa2  83c41c               add esp, 0x1c
// 007d3aa5  c3                   ret 
// library lua-5.1/lparser.c (function _fornum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
