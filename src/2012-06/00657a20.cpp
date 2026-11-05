// from server: 100% by auto
// roc 2012-06 00657a20  unit: seg_00650000  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657a20
//
// 00657a20  83ec20               sub esp, 0x20
// 00657a23  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00657a27  53                   push ebx
// 00657a28  56                   push esi
// 00657a29  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00657a2d  b043                 mov al, 0x43
// 00657a2f  57                   push edi
// 00657a30  88442411             mov byte ptr [esp + 0x11], al
// 00657a34  88442412             mov byte ptr [esp + 0x12], al
// 00657a38  8d44240c             lea eax, [esp + 0xc]
// 00657a3c  50                   push eax
// 00657a3d  33ff                 xor edi, edi
// 00657a3f  51                   push ecx
// 00657a40  56                   push esi
// 00657a41  c644241c69           mov byte ptr [esp + 0x1c], 0x69
// 00657a46  c644241f50           mov byte ptr [esp + 0x1f], 0x50
// 00657a4b  c644242000           mov byte ptr [esp + 0x20], 0
// 00657a50  897c242c             mov dword ptr [esp + 0x2c], edi
// 00657a54  897c2430             mov dword ptr [esp + 0x30], edi
// 00657a58  897c2434             mov dword ptr [esp + 0x34], edi
// 00657a5c  897c2424             mov dword ptr [esp + 0x24], edi
// 00657a60  897c2428             mov dword ptr [esp + 0x28], edi
// 00657a64  e8a7ecffff           call 0x656710
// 00657a69  8bd8                 mov ebx, eax
// 00657a6b  83c40c               add esp, 0xc
// 00657a6e  3bdf                 cmp ebx, edi
// 00657a70  0f8407010000         je 0x657b7d
// 00657a76  397c2438             cmp dword ptr [esp + 0x38], edi
// 00657a7a  740e                 je 0x657a8a
// 00657a7c  68289eb800           push 0xb89e28
// 00657a81  56                   push esi
// 00657a82  e8d967ffff           call 0x64e260
// 00657a87  83c408               add esp, 8
// 00657a8a  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00657a8e  55                   push ebp
// 00657a8f  3bc7                 cmp eax, edi
// 00657a91  7507                 jne 0x657a9a
// 00657a93  33ed                 xor ebp, ebp
// 00657a95  e99e000000           jmp 0x657b38
// 00657a9a  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 00657a9e  83fd03               cmp ebp, 3
// 00657aa1  7e41                 jle 0x657ae4
// 00657aa3  0fb638               movzx edi, byte ptr [eax]
// 00657aa6  0fb65001             movzx edx, byte ptr [eax + 1]
// 00657aaa  0fb64802             movzx ecx, byte ptr [eax + 2]
// 00657aae  c1e708               shl edi, 8
// 00657ab1  0bfa                 or edi, edx
// 00657ab3  0fb65003             movzx edx, byte ptr [eax + 3]
// 00657ab7  c1e708               shl edi, 8
// 00657aba  0bf9                 or edi, ecx
// 00657abc  c1e708               shl edi, 8
// 00657abf  0bfa                 or edi, edx
// 00657ac1  7d21                 jge 0x657ae4
// 00657ac3  68f49db800           push 0xb89df4
// 00657ac8  56                   push esi
// 00657ac9  e89267ffff           call 0x64e260
// 00657ace  8b442418             mov eax, dword ptr [esp + 0x18]
// 00657ad2  50                   push eax
// 00657ad3  56                   push esi
// 00657ad4  e8476affff           call 0x64e520
// 00657ad9  83c410               add esp, 0x10
// 00657adc  5d                   pop ebp
// 00657add  5f                   pop edi
// 00657ade  5e                   pop esi
// 00657adf  5b                   pop ebx
// 00657ae0  83c420               add esp, 0x20
// 00657ae3  c3                   ret 
// 00657ae4  3bef                 cmp ebp, edi
// 00657ae6  7d21                 jge 0x657b09
// 00657ae8  68c49db800           push 0xb89dc4
// 00657aed  56                   push esi
// 00657aee  e86d67ffff           call 0x64e260
// 00657af3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00657af7  51                   push ecx
// 00657af8  56                   push esi
// 00657af9  e8226affff           call 0x64e520
// 00657afe  83c410               add esp, 0x10
// 00657b01  5d                   pop ebp
// 00657b02  5f                   pop edi
// 00657b03  5e                   pop esi
// 00657b04  5b                   pop ebx
// 00657b05  83c420               add esp, 0x20
// 00657b08  c3                   ret 
// 00657b09  7e14                 jle 0x657b1f
// 00657b0b  68909db800           push 0xb89d90
// 00657b10  56                   push esi
// 00657b11  e84a67ffff           call 0x64e260
// 00657b16  8b442448             mov eax, dword ptr [esp + 0x48]
// 00657b1a  83c408               add esp, 8
// 00657b1d  8bef                 mov ebp, edi
// 00657b1f  85ed                 test ebp, ebp
// 00657b21  7415                 je 0x657b38
// 00657b23  50                   push eax
// 00657b24  8d7c2420             lea edi, [esp + 0x20]
// 00657b28  33c0                 xor eax, eax
// 00657b2a  8bcd                 mov ecx, ebp
// 00657b2c  8bd6                 mov edx, esi
// 00657b2e  e87de6ffff           call 0x6561b0
// 00657b33  83c404               add esp, 4
// 00657b36  8be8                 mov ebp, eax
// 00657b38  8d542b02             lea edx, [ebx + ebp + 2]
// 00657b3c  52                   push edx
// 00657b3d  8d442418             lea eax, [esp + 0x18]
// 00657b41  50                   push eax
// 00657b42  56                   push esi
// 00657b43  e878e5ffff           call 0x6560c0
// 00657b48  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00657b4c  c6441f0100           mov byte ptr [edi + ebx + 1], 0
// 00657b51  83c302               add ebx, 2
// 00657b54  53                   push ebx
// 00657b55  57                   push edi
// 00657b56  56                   push esi
// 00657b57  e8d4e5ffff           call 0x656130
// 00657b5c  83c418               add esp, 0x18
// 00657b5f  85ed                 test ebp, ebp
// 00657b61  7409                 je 0x657b6c
// 00657b63  8d44241c             lea eax, [esp + 0x1c]
// 00657b67  e8c4e8ffff           call 0x656430
// 00657b6c  56                   push esi
// 00657b6d  e8fee5ffff           call 0x656170
// 00657b72  57                   push edi
// 00657b73  56                   push esi
// 00657b74  e8a769ffff           call 0x64e520
// 00657b79  83c40c               add esp, 0xc
// 00657b7c  5d                   pop ebp
// 00657b7d  5f                   pop edi
// 00657b7e  5e                   pop esi
// 00657b7f  5b                   pop ebx
// 00657b80  83c420               add esp, 0x20
// 00657b83  c3                   ret 
// library libpng-1.2.40/pngwutil.c (function _png_write_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.40 pngwutil.c
