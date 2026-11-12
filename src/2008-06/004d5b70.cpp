// from server: 100% by auto
// roc 2008-06 004d5b70  unit: CSHA1  size: 447 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d5b70
//
// 004d5b70  83ec18               sub esp, 0x18
// 004d5b73  55                   push ebp
// 004d5b74  b871d90000           mov eax, 0xd971
// 004d5b79  57                   push edi
// 004d5b7a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004d5b7e  6689442414           mov word ptr [esp + 0x14], ax
// 004d5b83  ba6dce0000           mov edx, 0xce6d
// 004d5b88  b8bf580000           mov eax, 0x58bf
// 004d5b8d  894c240c             mov dword ptr [esp + 0xc], ecx
// 004d5b91  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004d5b99  6689542416           mov word ptr [esp + 0x16], dx
// 004d5b9e  6689442418           mov word ptr [esp + 0x18], ax
// 004d5ba3  85ff                 test edi, edi
// 004d5ba5  0f847a010000         je 0x4d5d25
// 004d5bab  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 004d5baf  83fd10               cmp ebp, 0x10
// 004d5bb2  0f8c6d010000         jl 0x4d5d25
// 004d5bb8  8bd5                 mov edx, ebp
// 004d5bba  81e20f000080         and edx, 0x8000000f
// 004d5bc0  7905                 jns 0x4d5bc7
// 004d5bc2  4a                   dec edx
// 004d5bc3  83caf0               or edx, 0xfffffff0
// 004d5bc6  42                   inc edx
// 004d5bc7  0f8558010000         jne 0x4d5d25
// 004d5bcd  8d45f0               lea eax, [ebp - 0x10]
// 004d5bd0  83f810               cmp eax, 0x10
// 004d5bd3  53                   push ebx
// 004d5bd4  56                   push esi
// 004d5bd5  0f8cbb000000         jl 0x4d5c96
// 004d5bdb  bd10000000           mov ebp, 0x10
// 004d5be0  2bef                 sub ebp, edi
// 004d5be2  c1e804               shr eax, 4
// 004d5be5  8d7710               lea esi, [edi + 0x10]
// 004d5be8  c744242cefffffff     mov dword ptr [esp + 0x2c], 0xffffffef
// 004d5bf0  896c2418             mov dword ptr [esp + 0x18], ebp
// 004d5bf4  89442410             mov dword ptr [esp + 0x10], eax
// 004d5bf8  eb0a                 jmp 0x4d5c04
// 004d5bfa  8d9b00000000         lea ebx, [ebx]
// 004d5c00  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004d5c04  56                   push esi
// 004d5c05  6a10                 push 0x10
// 004d5c07  8d8120010000         lea eax, [ecx + 0x120]
// 004d5c0d  56                   push esi
// 004d5c0e  50                   push eax
// 004d5c0f  8d8140020000         lea eax, [ecx + 0x240]
// 004d5c15  50                   push eax
// 004d5c16  e8a50f0000           call 0x4d6bc0
// 004d5c1b  83c414               add esp, 0x14
// 004d5c1e  33c9                 xor ecx, ecx
// 004d5c20  03ee                 add ebp, esi
// 004d5c22  8d442ff1             lea eax, [edi + ebp - 0xf]
// 004d5c26  8b542430             mov edx, dword ptr [esp + 0x30]
// 004d5c2a  3bea                 cmp ebp, edx
// 004d5c2c  7509                 jne 0x4d5c37
// 004d5c2e  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 004d5c32  8a1c03               mov bl, byte ptr [ebx + eax]
// 004d5c35  eb04                 jmp 0x4d5c3b
// 004d5c37  8a5c0e10             mov bl, byte ptr [esi + ecx + 0x10]
// 004d5c3b  3058ff               xor byte ptr [eax - 1], bl
// 004d5c3e  3bea                 cmp ebp, edx
// 004d5c40  7506                 jne 0x4d5c48
// 004d5c42  8a5c3901             mov bl, byte ptr [ecx + edi + 1]
// 004d5c46  eb04                 jmp 0x4d5c4c
// 004d5c48  8a5c0e11             mov bl, byte ptr [esi + ecx + 0x11]
// 004d5c4c  3018                 xor byte ptr [eax], bl
// 004d5c4e  3bea                 cmp ebp, edx
// 004d5c50  7506                 jne 0x4d5c58
// 004d5c52  8a5c3902             mov bl, byte ptr [ecx + edi + 2]
// 004d5c56  eb04                 jmp 0x4d5c5c
// 004d5c58  8a5c0e12             mov bl, byte ptr [esi + ecx + 0x12]
// 004d5c5c  305801               xor byte ptr [eax + 1], bl
// 004d5c5f  3bea                 cmp ebp, edx
// 004d5c61  7506                 jne 0x4d5c69
// 004d5c63  8a543903             mov dl, byte ptr [ecx + edi + 3]
// 004d5c67  eb04                 jmp 0x4d5c6d
// 004d5c69  8a540e13             mov dl, byte ptr [esi + ecx + 0x13]
// 004d5c6d  305002               xor byte ptr [eax + 2], dl
// 004d5c70  83c104               add ecx, 4
// 004d5c73  83c004               add eax, 4
// 004d5c76  83f910               cmp ecx, 0x10
// 004d5c79  72ab                 jb 0x4d5c26
// 004d5c7b  836c242c10           sub dword ptr [esp + 0x2c], 0x10
// 004d5c80  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d5c84  83c610               add esi, 0x10
// 004d5c87  836c241001           sub dword ptr [esp + 0x10], 1
// 004d5c8c  0f856effffff         jne 0x4d5c00
// 004d5c92  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 004d5c96  57                   push edi
// 004d5c97  6a10                 push 0x10
// 004d5c99  8d8120010000         lea eax, [ecx + 0x120]
// 004d5c9f  57                   push edi
// 004d5ca0  50                   push eax
// 004d5ca1  81c140020000         add ecx, 0x240
// 004d5ca7  51                   push ecx
// 004d5ca8  e8130f0000           call 0x4d6bc0
// 004d5cad  8a4705               mov al, byte ptr [edi + 5]
// 004d5cb0  8b1f                 mov ebx, dword ptr [edi]
// 004d5cb2  240f                 and al, 0xf
// 004d5cb4  0fb6f0               movzx esi, al
// 004d5cb7  2bee                 sub ebp, esi
// 004d5cb9  8d45fa               lea eax, [ebp - 6]
// 004d5cbc  8b6c244c             mov ebp, dword ptr [esp + 0x4c]
// 004d5cc0  83c414               add esp, 0x14
// 004d5cc3  8d4c3002             lea ecx, [eax + esi + 2]
// 004d5cc7  51                   push ecx
// 004d5cc8  8d5704               lea edx, [edi + 4]
// 004d5ccb  52                   push edx
// 004d5ccc  8d4c2424             lea ecx, [esp + 0x24]
// 004d5cd0  894500               mov dword ptr [ebp], eax
// 004d5cd3  e828120000           call 0x4d6f00
// 004d5cd8  3b5c2424             cmp ebx, dword ptr [esp + 0x24]
// 004d5cdc  740c                 je 0x4d5cea
// 004d5cde  5e                   pop esi
// 004d5cdf  5b                   pop ebx
// 004d5ce0  5f                   pop edi
// 004d5ce1  32c0                 xor al, al
// 004d5ce3  5d                   pop ebp
// 004d5ce4  83c418               add esp, 0x18
// 004d5ce7  c21000               ret 0x10
// 004d5cea  8b4d00               mov ecx, dword ptr [ebp]
// 004d5ced  8b442434             mov eax, dword ptr [esp + 0x34]
// 004d5cf1  51                   push ecx
// 004d5cf2  8d543e06             lea edx, [esi + edi + 6]
// 004d5cf6  52                   push edx
// 004d5cf7  50                   push eax
// 004d5cf8  3bf8                 cmp edi, eax
// 004d5cfa  7515                 jne 0x4d5d11
// 004d5cfc  ff15cc278000         call dword ptr [0x8027cc]
// 004d5d02  83c40c               add esp, 0xc
// 004d5d05  5e                   pop esi
// 004d5d06  5b                   pop ebx
// 004d5d07  5f                   pop edi
// 004d5d08  b001                 mov al, 1
// 004d5d0a  5d                   pop ebp
// 004d5d0b  83c418               add esp, 0x18
// 004d5d0e  c21000               ret 0x10
// 004d5d11  e8caba1c00           call 0x6a17e0
// 004d5d16  83c40c               add esp, 0xc
// 004d5d19  5e                   pop esi
// 004d5d1a  5b                   pop ebx
// 004d5d1b  5f                   pop edi
// 004d5d1c  b001                 mov al, 1
// 004d5d1e  5d                   pop ebp
// 004d5d1f  83c418               add esp, 0x18
// 004d5d22  c21000               ret 0x10
// 004d5d25  5f                   pop edi
// 004d5d26  32c0                 xor al, al
// 004d5d28  5d                   pop ebp
// 004d5d29  83c418               add esp, 0x18
// 004d5d2c  c21000               ret 0x10
// library openrbx-raknet/DataBlockEncryptor.cpp (function ?Decrypt@DataBlockEncryptor@@QAE_NPAEH0PAH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DataBlockEncryptor.cpp
