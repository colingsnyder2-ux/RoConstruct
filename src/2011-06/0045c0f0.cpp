// from server: 100% by auto
// roc 2011-06 0045c0f0  unit: VCRoblox3D::?$CComObject  size: 775 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045c0f0
//
// 0045c0f0  55                   push ebp
// 0045c0f1  8d6c2494             lea ebp, [esp - 0x6c]
// 0045c0f5  81ec24010000         sub esp, 0x124
// 0045c0fb  53                   push ebx
// 0045c0fc  8b5d78               mov ebx, dword ptr [ebp + 0x78]
// 0045c0ff  56                   push esi
// 0045c100  57                   push edi
// 0045c101  c7456800000000       mov dword ptr [ebp + 0x68], 0
// 0045c108  85db                 test ebx, ebx
// 0045c10a  0f84d3020000         je 0x45c3e3
// 0045c110  8b7d74               mov edi, dword ptr [ebp + 0x74]
// 0045c113  8b07                 mov eax, dword ptr [edi]
// 0045c115  3b058816ac00         cmp eax, dword ptr [0xac1688]
// 0045c11b  7525                 jne 0x45c142
// 0045c11d  8b4f04               mov ecx, dword ptr [edi + 4]
// 0045c120  3b0d8c16ac00         cmp ecx, dword ptr [0xac168c]
// 0045c126  751a                 jne 0x45c142
// 0045c128  8b5708               mov edx, dword ptr [edi + 8]
// 0045c12b  3b159016ac00         cmp edx, dword ptr [0xac1690]
// 0045c131  750f                 jne 0x45c142
// 0045c133  8b470c               mov eax, dword ptr [edi + 0xc]
// 0045c136  3b059416ac00         cmp eax, dword ptr [0xac1694]
// 0045c13c  0f84a1020000         je 0x45c3e3
// 0045c142  8d4d68               lea ecx, [ebp + 0x68]
// 0045c145  51                   push ecx
// 0045c146  68d8e6a600           push 0xa6e6d8
// 0045c14b  6a01                 push 1
// 0045c14d  6a00                 push 0
// 0045c14f  686816ac00           push 0xac1668
// 0045c154  ff158030a400         call dword ptr [0xa43080]
// 0045c15a  85c0                 test eax, eax
// 0045c15c  7d27                 jge 0x45c185
// 0045c15e  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0045c161  85c0                 test eax, eax
// 0045c163  0f847a020000         je 0x45c3e3
// 0045c169  8b10                 mov edx, dword ptr [eax]
// 0045c16b  50                   push eax
// 0045c16c  8b4208               mov eax, dword ptr [edx + 8]
// 0045c16f  ffd0                 call eax
// 0045c171  33c0                 xor eax, eax
// 0045c173  8da53cffffff         lea esp, [ebp - 0xc4]
// 0045c179  5f                   pop edi
// 0045c17a  5e                   pop esi
// 0045c17b  5b                   pop ebx
// 0045c17c  83c56c               add ebp, 0x6c
// 0045c17f  8be5                 mov esp, ebp
// 0045c181  5d                   pop ebp
// 0045c182  c20c00               ret 0xc
// 0045c185  833b00               cmp dword ptr [ebx], 0
// 0045c188  747c                 je 0x45c206
// 0045c18a  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0045c18e  8b4304               mov eax, dword ptr [ebx + 4]
// 0045c191  8b08                 mov ecx, dword ptr [eax]
// 0045c193  894d48               mov dword ptr [ebp + 0x48], ecx
// 0045c196  8b5004               mov edx, dword ptr [eax + 4]
// 0045c199  89554c               mov dword ptr [ebp + 0x4c], edx
// 0045c19c  8b4808               mov ecx, dword ptr [eax + 8]
// 0045c19f  894d50               mov dword ptr [ebp + 0x50], ecx
// 0045c1a2  8b500c               mov edx, dword ptr [eax + 0xc]
// 0045c1a5  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0045c1a8  895554               mov dword ptr [ebp + 0x54], edx
// 0045c1ab  8b08                 mov ecx, dword ptr [eax]
// 0045c1ad  8d5548               lea edx, [ebp + 0x48]
// 0045c1b0  52                   push edx
// 0045c1b1  6a01                 push 1
// 0045c1b3  57                   push edi
// 0045c1b4  50                   push eax
// 0045c1b5  7438                 je 0x45c1ef
// 0045c1b7  833b01               cmp dword ptr [ebx], 1
// 0045c1ba  7505                 jne 0x45c1c1
// 0045c1bc  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0045c1bf  eb03                 jmp 0x45c1c4
// 0045c1c1  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0045c1c4  ffd0                 call eax
// 0045c1c6  8bf0                 mov esi, eax
// 0045c1c8  85f6                 test esi, esi
// 0045c1ca  7d32                 jge 0x45c1fe
// 0045c1cc  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0045c1cf  85c0                 test eax, eax
// 0045c1d1  7408                 je 0x45c1db
// 0045c1d3  8b08                 mov ecx, dword ptr [eax]
// 0045c1d5  8b5108               mov edx, dword ptr [ecx + 8]
// 0045c1d8  50                   push eax
// 0045c1d9  ffd2                 call edx
// 0045c1db  8bc6                 mov eax, esi
// 0045c1dd  8da53cffffff         lea esp, [ebp - 0xc4]
// 0045c1e3  5f                   pop edi
// 0045c1e4  5e                   pop esi
// 0045c1e5  5b                   pop ebx
// 0045c1e6  83c56c               add ebp, 0x6c
// 0045c1e9  8be5                 mov esp, ebp
// 0045c1eb  5d                   pop ebp
// 0045c1ec  c20c00               ret 0xc
// 0045c1ef  833b01               cmp dword ptr [ebx], 1
// 0045c1f2  7505                 jne 0x45c1f9
// 0045c1f4  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0045c1f7  eb03                 jmp 0x45c1fc
// 0045c1f9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0045c1fc  ffd0                 call eax
// 0045c1fe  83c308               add ebx, 8
// 0045c201  833b00               cmp dword ptr [ebx], 0
// 0045c204  7584                 jne 0x45c18a
// 0045c206  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0045c20a  0f85c4010000         jne 0x45c3d4
// 0045c210  6a40                 push 0x40
// 0045c212  8d8548ffffff         lea eax, [ebp - 0xb8]
// 0045c218  50                   push eax
// 0045c219  57                   push edi
// 0045c21a  ff15b830a400         call dword ptr [0xa430b8]
// 0045c220  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0045c226  51                   push ecx
// 0045c227  c7457800000000       mov dword ptr [ebp + 0x78], 0
// 0045c22e  ff155803a400         call dword ptr [0xa40358]
// 0045c234  40                   inc eax
// 0045c235  6a02                 push 2
// 0045c237  50                   push eax
// 0045c238  8d557c               lea edx, [ebp + 0x7c]
// 0045c23b  52                   push edx
// 0045c23c  89457c               mov dword ptr [ebp + 0x7c], eax
// 0045c23f  e85c72faff           call 0x4034a0
// 0045c244  83c40c               add esp, 0xc
// 0045c247  85c0                 test eax, eax
// 0045c249  0f8c7d010000         jl 0x45c3cc
// 0045c24f  8b757c               mov esi, dword ptr [ebp + 0x7c]
// 0045c252  81fe00040000         cmp esi, 0x400
// 0045c258  7f18                 jg 0x45c272
// 0045c25a  56                   push esi
// 0045c25b  e8c083faff           call 0x404620
// 0045c260  83c404               add esp, 4
// 0045c263  84c0                 test al, al
// 0045c265  740b                 je 0x45c272
// 0045c267  8bc6                 mov eax, esi
// 0045c269  e812f03a00           call 0x80b280
// 0045c26e  8bc4                 mov eax, esp
// 0045c270  eb09                 jmp 0x45c27b
// 0045c272  56                   push esi
// 0045c273  8d4d78               lea ecx, [ebp + 0x78]
// 0045c276  e85589faff           call 0x404bd0
// 0045c27b  6a03                 push 3
// 0045c27d  56                   push esi
// 0045c27e  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0045c284  51                   push ecx
// 0045c285  50                   push eax
// 0045c286  e8a572faff           call 0x403530
// 0045c28b  8bf0                 mov esi, eax
// 0045c28d  85f6                 test esi, esi
// 0045c28f  0f8437010000         je 0x45c3cc
// 0045c295  68d0e6a600           push 0xa6e6d0
// 0045c29a  8d55c8               lea edx, [ebp - 0x38]
// 0045c29d  6880000000           push 0x80
// 0045c2a2  52                   push edx
// 0045c2a3  e8f8c4ffff           call 0x4587a0
// 0045c2a8  56                   push esi
// 0045c2a9  8d45c8               lea eax, [ebp - 0x38]
// 0045c2ac  6880000000           push 0x80
// 0045c2b1  50                   push eax
// 0045c2b2  e809c5ffff           call 0x4587c0
// 0045c2b7  68b8e6a600           push 0xa6e6b8
// 0045c2bc  8d4dc8               lea ecx, [ebp - 0x38]
// 0045c2bf  6880000000           push 0x80
// 0045c2c4  51                   push ecx
// 0045c2c5  e8f6c4ffff           call 0x4587c0
// 0045c2ca  83c424               add esp, 0x24
// 0045c2cd  6819000200           push 0x20019
// 0045c2d2  8d55c8               lea edx, [ebp - 0x38]
// 0045c2d5  33ff                 xor edi, edi
// 0045c2d7  52                   push edx
// 0045c2d8  6800000080           push 0x80000000
// 0045c2dd  8d4d60               lea ecx, [ebp + 0x60]
// 0045c2e0  c7455800000080       mov dword ptr [ebp + 0x58], 0x80000000
// 0045c2e7  897d5c               mov dword ptr [ebp + 0x5c], edi
// 0045c2ea  897d60               mov dword ptr [ebp + 0x60], edi
// 0045c2ed  897d64               mov dword ptr [ebp + 0x64], edi
// 0045c2f0  897d7c               mov dword ptr [ebp + 0x7c], edi
// 0045c2f3  e8b875faff           call 0x4038b0
// 0045c2f8  85c0                 test eax, eax
// 0045c2fa  7537                 jne 0x45c333
// 0045c2fc  8b4d60               mov ecx, dword ptr [ebp + 0x60]
// 0045c2ff  57                   push edi
// 0045c300  57                   push edi
// 0045c301  57                   push edi
// 0045c302  57                   push edi
// 0045c303  57                   push edi
// 0045c304  57                   push edi
// 0045c305  57                   push edi
// 0045c306  8d457c               lea eax, [ebp + 0x7c]
// 0045c309  50                   push eax
// 0045c30a  57                   push edi
// 0045c30b  57                   push edi
// 0045c30c  57                   push edi
// 0045c30d  51                   push ecx
// 0045c30e  ff154800a400         call dword ptr [0xa40048]
// 0045c314  8d4d60               lea ecx, [ebp + 0x60]
// 0045c317  8bd8                 mov ebx, eax
// 0045c319  e86275faff           call 0x403880
// 0045c31e  3bdf                 cmp ebx, edi
// 0045c320  7511                 jne 0x45c333
// 0045c322  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0045c325  750c                 jne 0x45c333
// 0045c327  8d55c8               lea edx, [ebp - 0x38]
// 0045c32a  52                   push edx
// 0045c32b  8d4d58               lea ecx, [ebp + 0x58]
// 0045c32e  e8ed74faff           call 0x403820
// 0045c333  68d0e6a600           push 0xa6e6d0
// 0045c338  8d45c8               lea eax, [ebp - 0x38]
// 0045c33b  6880000000           push 0x80
// 0045c340  50                   push eax
// 0045c341  e85ac4ffff           call 0x4587a0
// 0045c346  56                   push esi
// 0045c347  8d4dc8               lea ecx, [ebp - 0x38]
// 0045c34a  6880000000           push 0x80
// 0045c34f  51                   push ecx
// 0045c350  e86bc4ffff           call 0x4587c0
// 0045c355  68a0e6a600           push 0xa6e6a0
// 0045c35a  8d55c8               lea edx, [ebp - 0x38]
// 0045c35d  6880000000           push 0x80
// 0045c362  52                   push edx
// 0045c363  e858c4ffff           call 0x4587c0
// 0045c368  83c424               add esp, 0x24
// 0045c36b  6819000200           push 0x20019
// 0045c370  8d45c8               lea eax, [ebp - 0x38]
// 0045c373  50                   push eax
// 0045c374  6800000080           push 0x80000000
// 0045c379  8d4d60               lea ecx, [ebp + 0x60]
// 0045c37c  e82f75faff           call 0x4038b0
// 0045c381  85c0                 test eax, eax
// 0045c383  7537                 jne 0x45c3bc
// 0045c385  8b5560               mov edx, dword ptr [ebp + 0x60]
// 0045c388  57                   push edi
// 0045c389  57                   push edi
// 0045c38a  57                   push edi
// 0045c38b  57                   push edi
// 0045c38c  57                   push edi
// 0045c38d  57                   push edi
// 0045c38e  57                   push edi
// 0045c38f  8d4d7c               lea ecx, [ebp + 0x7c]
// 0045c392  51                   push ecx
// 0045c393  57                   push edi
// 0045c394  57                   push edi
// 0045c395  57                   push edi
// 0045c396  52                   push edx
// 0045c397  ff154800a400         call dword ptr [0xa40048]
// 0045c39d  8d4d60               lea ecx, [ebp + 0x60]
// 0045c3a0  8bf0                 mov esi, eax
// 0045c3a2  e8d974faff           call 0x403880
// 0045c3a7  3bf7                 cmp esi, edi
// 0045c3a9  7511                 jne 0x45c3bc
// 0045c3ab  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0045c3ae  750c                 jne 0x45c3bc
// 0045c3b0  8d45c8               lea eax, [ebp - 0x38]
// 0045c3b3  50                   push eax
// 0045c3b4  8d4d58               lea ecx, [ebp + 0x58]
// 0045c3b7  e86474faff           call 0x403820
// 0045c3bc  8d4d60               lea ecx, [ebp + 0x60]
// 0045c3bf  e80c85faff           call 0x4048d0
// 0045c3c4  8d4d58               lea ecx, [ebp + 0x58]
// 0045c3c7  e80485faff           call 0x4048d0
// 0045c3cc  8d4d78               lea ecx, [ebp + 0x78]
// 0045c3cf  e8ec7efaff           call 0x4042c0
// 0045c3d4  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0045c3d7  85c0                 test eax, eax
// 0045c3d9  7408                 je 0x45c3e3
// 0045c3db  8b08                 mov ecx, dword ptr [eax]
// 0045c3dd  8b5108               mov edx, dword ptr [ecx + 8]
// 0045c3e0  50                   push eax
// 0045c3e1  ffd2                 call edx
// 0045c3e3  33c0                 xor eax, eax
// 0045c3e5  8da53cffffff         lea esp, [ebp - 0xc4]
// 0045c3eb  5f                   pop edi
// 0045c3ec  5e                   pop esi
// 0045c3ed  5b                   pop ebx
// 0045c3ee  83c56c               add ebp, 0x6c
// 0045c3f1  8be5                 mov esp, ebp
// 0045c3f3  5d                   pop ebp
// 0045c3f4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlRegisterClassCategoriesHelper@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
