// from server: 100% by auto
// roc 2008-06 0044b1b0  unit: CRobloxApp  size: 775 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044b1b0
//
// 0044b1b0  55                   push ebp
// 0044b1b1  8d6c2494             lea ebp, [esp - 0x6c]
// 0044b1b5  81ec24010000         sub esp, 0x124
// 0044b1bb  53                   push ebx
// 0044b1bc  8b5d78               mov ebx, dword ptr [ebp + 0x78]
// 0044b1bf  56                   push esi
// 0044b1c0  57                   push edi
// 0044b1c1  c7456800000000       mov dword ptr [ebp + 0x68], 0
// 0044b1c8  85db                 test ebx, ebx
// 0044b1ca  0f84d3020000         je 0x44b4a3
// 0044b1d0  8b7d74               mov edi, dword ptr [ebp + 0x74]
// 0044b1d3  8b07                 mov eax, dword ptr [edi]
// 0044b1d5  3b05ec018500         cmp eax, dword ptr [0x8501ec]
// 0044b1db  7525                 jne 0x44b202
// 0044b1dd  8b4f04               mov ecx, dword ptr [edi + 4]
// 0044b1e0  3b0df0018500         cmp ecx, dword ptr [0x8501f0]
// 0044b1e6  751a                 jne 0x44b202
// 0044b1e8  8b5708               mov edx, dword ptr [edi + 8]
// 0044b1eb  3b15f4018500         cmp edx, dword ptr [0x8501f4]
// 0044b1f1  750f                 jne 0x44b202
// 0044b1f3  8b470c               mov eax, dword ptr [edi + 0xc]
// 0044b1f6  3b05f8018500         cmp eax, dword ptr [0x8501f8]
// 0044b1fc  0f84a1020000         je 0x44b4a3
// 0044b202  8d4d68               lea ecx, [ebp + 0x68]
// 0044b205  51                   push ecx
// 0044b206  6878698100           push 0x816978
// 0044b20b  6a01                 push 1
// 0044b20d  6a00                 push 0
// 0044b20f  683c028500           push 0x85023c
// 0044b214  ff1518418000         call dword ptr [0x804118]
// 0044b21a  85c0                 test eax, eax
// 0044b21c  7d27                 jge 0x44b245
// 0044b21e  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044b221  85c0                 test eax, eax
// 0044b223  0f847a020000         je 0x44b4a3
// 0044b229  8b10                 mov edx, dword ptr [eax]
// 0044b22b  50                   push eax
// 0044b22c  8b4208               mov eax, dword ptr [edx + 8]
// 0044b22f  ffd0                 call eax
// 0044b231  33c0                 xor eax, eax
// 0044b233  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044b239  5f                   pop edi
// 0044b23a  5e                   pop esi
// 0044b23b  5b                   pop ebx
// 0044b23c  83c56c               add ebp, 0x6c
// 0044b23f  8be5                 mov esp, ebp
// 0044b241  5d                   pop ebp
// 0044b242  c20c00               ret 0xc
// 0044b245  833b00               cmp dword ptr [ebx], 0
// 0044b248  747c                 je 0x44b2c6
// 0044b24a  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0044b24e  8b4304               mov eax, dword ptr [ebx + 4]
// 0044b251  8b08                 mov ecx, dword ptr [eax]
// 0044b253  894d48               mov dword ptr [ebp + 0x48], ecx
// 0044b256  8b5004               mov edx, dword ptr [eax + 4]
// 0044b259  89554c               mov dword ptr [ebp + 0x4c], edx
// 0044b25c  8b4808               mov ecx, dword ptr [eax + 8]
// 0044b25f  894d50               mov dword ptr [ebp + 0x50], ecx
// 0044b262  8b500c               mov edx, dword ptr [eax + 0xc]
// 0044b265  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044b268  895554               mov dword ptr [ebp + 0x54], edx
// 0044b26b  8b08                 mov ecx, dword ptr [eax]
// 0044b26d  8d5548               lea edx, [ebp + 0x48]
// 0044b270  52                   push edx
// 0044b271  6a01                 push 1
// 0044b273  57                   push edi
// 0044b274  50                   push eax
// 0044b275  7438                 je 0x44b2af
// 0044b277  833b01               cmp dword ptr [ebx], 1
// 0044b27a  7505                 jne 0x44b281
// 0044b27c  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0044b27f  eb03                 jmp 0x44b284
// 0044b281  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0044b284  ffd0                 call eax
// 0044b286  8bf0                 mov esi, eax
// 0044b288  85f6                 test esi, esi
// 0044b28a  7d32                 jge 0x44b2be
// 0044b28c  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044b28f  85c0                 test eax, eax
// 0044b291  7408                 je 0x44b29b
// 0044b293  8b08                 mov ecx, dword ptr [eax]
// 0044b295  8b5108               mov edx, dword ptr [ecx + 8]
// 0044b298  50                   push eax
// 0044b299  ffd2                 call edx
// 0044b29b  8bc6                 mov eax, esi
// 0044b29d  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044b2a3  5f                   pop edi
// 0044b2a4  5e                   pop esi
// 0044b2a5  5b                   pop ebx
// 0044b2a6  83c56c               add ebp, 0x6c
// 0044b2a9  8be5                 mov esp, ebp
// 0044b2ab  5d                   pop ebp
// 0044b2ac  c20c00               ret 0xc
// 0044b2af  833b01               cmp dword ptr [ebx], 1
// 0044b2b2  7505                 jne 0x44b2b9
// 0044b2b4  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0044b2b7  eb03                 jmp 0x44b2bc
// 0044b2b9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0044b2bc  ffd0                 call eax
// 0044b2be  83c308               add ebx, 8
// 0044b2c1  833b00               cmp dword ptr [ebx], 0
// 0044b2c4  7584                 jne 0x44b24a
// 0044b2c6  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0044b2ca  0f85c4010000         jne 0x44b494
// 0044b2d0  6a40                 push 0x40
// 0044b2d2  8d8548ffffff         lea eax, [ebp - 0xb8]
// 0044b2d8  50                   push eax
// 0044b2d9  57                   push edi
// 0044b2da  ff1528418000         call dword ptr [0x804128]
// 0044b2e0  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0044b2e6  51                   push ecx
// 0044b2e7  c7457800000000       mov dword ptr [ebp + 0x78], 0
// 0044b2ee  ff15e8228000         call dword ptr [0x8022e8]
// 0044b2f4  40                   inc eax
// 0044b2f5  6a02                 push 2
// 0044b2f7  50                   push eax
// 0044b2f8  8d557c               lea edx, [ebp + 0x7c]
// 0044b2fb  52                   push edx
// 0044b2fc  89457c               mov dword ptr [ebp + 0x7c], eax
// 0044b2ff  e80c64fbff           call 0x401710
// 0044b304  83c40c               add esp, 0xc
// 0044b307  85c0                 test eax, eax
// 0044b309  0f8c7d010000         jl 0x44b48c
// 0044b30f  8b757c               mov esi, dword ptr [ebp + 0x7c]
// 0044b312  81fe00040000         cmp esi, 0x400
// 0044b318  7f18                 jg 0x44b332
// 0044b31a  56                   push esi
// 0044b31b  e8f072fbff           call 0x402610
// 0044b320  83c404               add esp, 4
// 0044b323  84c0                 test al, al
// 0044b325  740b                 je 0x44b332
// 0044b327  8bc6                 mov eax, esi
// 0044b329  e832622500           call 0x6a1560
// 0044b32e  8bc4                 mov eax, esp
// 0044b330  eb09                 jmp 0x44b33b
// 0044b332  56                   push esi
// 0044b333  8d4d78               lea ecx, [ebp + 0x78]
// 0044b336  e8157cfbff           call 0x402f50
// 0044b33b  6a03                 push 3
// 0044b33d  56                   push esi
// 0044b33e  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 0044b344  51                   push ecx
// 0044b345  50                   push eax
// 0044b346  e85564fbff           call 0x4017a0
// 0044b34b  8bf0                 mov esi, eax
// 0044b34d  85f6                 test esi, esi
// 0044b34f  0f8437010000         je 0x44b48c
// 0044b355  6870698100           push 0x816970
// 0044b35a  8d55c8               lea edx, [ebp - 0x38]
// 0044b35d  6880000000           push 0x80
// 0044b362  52                   push edx
// 0044b363  e868e0ffff           call 0x4493d0
// 0044b368  56                   push esi
// 0044b369  8d45c8               lea eax, [ebp - 0x38]
// 0044b36c  6880000000           push 0x80
// 0044b371  50                   push eax
// 0044b372  e879e0ffff           call 0x4493f0
// 0044b377  6858698100           push 0x816958
// 0044b37c  8d4dc8               lea ecx, [ebp - 0x38]
// 0044b37f  6880000000           push 0x80
// 0044b384  51                   push ecx
// 0044b385  e866e0ffff           call 0x4493f0
// 0044b38a  83c424               add esp, 0x24
// 0044b38d  6819000200           push 0x20019
// 0044b392  8d55c8               lea edx, [ebp - 0x38]
// 0044b395  33ff                 xor edi, edi
// 0044b397  52                   push edx
// 0044b398  6800000080           push 0x80000000
// 0044b39d  8d4d60               lea ecx, [ebp + 0x60]
// 0044b3a0  c7455800000080       mov dword ptr [ebp + 0x58], 0x80000000
// 0044b3a7  897d5c               mov dword ptr [ebp + 0x5c], edi
// 0044b3aa  897d60               mov dword ptr [ebp + 0x60], edi
// 0044b3ad  897d64               mov dword ptr [ebp + 0x64], edi
// 0044b3b0  897d7c               mov dword ptr [ebp + 0x7c], edi
// 0044b3b3  e8c868fbff           call 0x401c80
// 0044b3b8  85c0                 test eax, eax
// 0044b3ba  7537                 jne 0x44b3f3
// 0044b3bc  8b4d60               mov ecx, dword ptr [ebp + 0x60]
// 0044b3bf  57                   push edi
// 0044b3c0  57                   push edi
// 0044b3c1  57                   push edi
// 0044b3c2  57                   push edi
// 0044b3c3  57                   push edi
// 0044b3c4  57                   push edi
// 0044b3c5  57                   push edi
// 0044b3c6  8d457c               lea eax, [ebp + 0x7c]
// 0044b3c9  50                   push eax
// 0044b3ca  57                   push edi
// 0044b3cb  57                   push edi
// 0044b3cc  57                   push edi
// 0044b3cd  51                   push ecx
// 0044b3ce  ff1518208000         call dword ptr [0x802018]
// 0044b3d4  8d4d60               lea ecx, [ebp + 0x60]
// 0044b3d7  8bd8                 mov ebx, eax
// 0044b3d9  e87268fbff           call 0x401c50
// 0044b3de  3bdf                 cmp ebx, edi
// 0044b3e0  7511                 jne 0x44b3f3
// 0044b3e2  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0044b3e5  750c                 jne 0x44b3f3
// 0044b3e7  8d55c8               lea edx, [ebp - 0x38]
// 0044b3ea  52                   push edx
// 0044b3eb  8d4d58               lea ecx, [ebp + 0x58]
// 0044b3ee  e8fd67fbff           call 0x401bf0
// 0044b3f3  6870698100           push 0x816970
// 0044b3f8  8d45c8               lea eax, [ebp - 0x38]
// 0044b3fb  6880000000           push 0x80
// 0044b400  50                   push eax
// 0044b401  e8cadfffff           call 0x4493d0
// 0044b406  56                   push esi
// 0044b407  8d4dc8               lea ecx, [ebp - 0x38]
// 0044b40a  6880000000           push 0x80
// 0044b40f  51                   push ecx
// 0044b410  e8dbdfffff           call 0x4493f0
// 0044b415  6840698100           push 0x816940
// 0044b41a  8d55c8               lea edx, [ebp - 0x38]
// 0044b41d  6880000000           push 0x80
// 0044b422  52                   push edx
// 0044b423  e8c8dfffff           call 0x4493f0
// 0044b428  83c424               add esp, 0x24
// 0044b42b  6819000200           push 0x20019
// 0044b430  8d45c8               lea eax, [ebp - 0x38]
// 0044b433  50                   push eax
// 0044b434  6800000080           push 0x80000000
// 0044b439  8d4d60               lea ecx, [ebp + 0x60]
// 0044b43c  e83f68fbff           call 0x401c80
// 0044b441  85c0                 test eax, eax
// 0044b443  7537                 jne 0x44b47c
// 0044b445  8b5560               mov edx, dword ptr [ebp + 0x60]
// 0044b448  57                   push edi
// 0044b449  57                   push edi
// 0044b44a  57                   push edi
// 0044b44b  57                   push edi
// 0044b44c  57                   push edi
// 0044b44d  57                   push edi
// 0044b44e  57                   push edi
// 0044b44f  8d4d7c               lea ecx, [ebp + 0x7c]
// 0044b452  51                   push ecx
// 0044b453  57                   push edi
// 0044b454  57                   push edi
// 0044b455  57                   push edi
// 0044b456  52                   push edx
// 0044b457  ff1518208000         call dword ptr [0x802018]
// 0044b45d  8d4d60               lea ecx, [ebp + 0x60]
// 0044b460  8bf0                 mov esi, eax
// 0044b462  e8e967fbff           call 0x401c50
// 0044b467  3bf7                 cmp esi, edi
// 0044b469  7511                 jne 0x44b47c
// 0044b46b  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0044b46e  750c                 jne 0x44b47c
// 0044b470  8d45c8               lea eax, [ebp - 0x38]
// 0044b473  50                   push eax
// 0044b474  8d4d58               lea ecx, [ebp + 0x58]
// 0044b477  e87467fbff           call 0x401bf0
// 0044b47c  8d4d60               lea ecx, [ebp + 0x60]
// 0044b47f  e89c76fbff           call 0x402b20
// 0044b484  8d4d58               lea ecx, [ebp + 0x58]
// 0044b487  e89476fbff           call 0x402b20
// 0044b48c  8d4d78               lea ecx, [ebp + 0x78]
// 0044b48f  e8bc5cfbff           call 0x401150
// 0044b494  8b4568               mov eax, dword ptr [ebp + 0x68]
// 0044b497  85c0                 test eax, eax
// 0044b499  7408                 je 0x44b4a3
// 0044b49b  8b08                 mov ecx, dword ptr [eax]
// 0044b49d  8b5108               mov edx, dword ptr [ecx + 8]
// 0044b4a0  50                   push eax
// 0044b4a1  ffd2                 call edx
// 0044b4a3  33c0                 xor eax, eax
// 0044b4a5  8da53cffffff         lea esp, [ebp - 0xc4]
// 0044b4ab  5f                   pop edi
// 0044b4ac  5e                   pop esi
// 0044b4ad  5b                   pop ebx
// 0044b4ae  83c56c               add ebp, 0x6c
// 0044b4b1  8be5                 mov esp, ebp
// 0044b4b3  5d                   pop ebp
// 0044b4b4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlRegisterClassCategoriesHelper@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
