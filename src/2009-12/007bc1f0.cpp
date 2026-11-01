// from server: 100% by auto
// roc 2009-12 007bc1f0  unit: RBX::SpatialFilter  size: 379 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bc1f0
//
// 007bc1f0  55                   push ebp
// 007bc1f1  8bec                 mov ebp, esp
// 007bc1f3  6aff                 push -1
// 007bc1f5  6840619500           push 0x956140
// 007bc1fa  64a100000000         mov eax, dword ptr fs:[0]
// 007bc200  50                   push eax
// 007bc201  64892500000000       mov dword ptr fs:[0], esp
// 007bc208  83ec1c               sub esp, 0x1c
// 007bc20b  53                   push ebx
// 007bc20c  56                   push esi
// 007bc20d  8bf1                 mov esi, ecx
// 007bc20f  57                   push edi
// 007bc210  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007bc213  8965f0               mov dword ptr [ebp - 0x10], esp
// 007bc216  8975e0               mov dword ptr [ebp - 0x20], esi
// 007bc219  85ff                 test edi, edi
// 007bc21b  7504                 jne 0x7bc221
// 007bc21d  33c9                 xor ecx, ecx
// 007bc21f  eb0a                 jmp 0x7bc22b
// 007bc221  8b4614               mov eax, dword ptr [esi + 0x14]
// 007bc224  2bc7                 sub eax, edi
// 007bc226  c1f803               sar eax, 3
// 007bc229  8bc8                 mov ecx, eax
// 007bc22b  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 007bc22e  85db                 test ebx, ebx
// 007bc230  0f84cb020000         je 0x7bc501
// 007bc236  8b5610               mov edx, dword ptr [esi + 0x10]
// 007bc239  8bc2                 mov eax, edx
// 007bc23b  2bc7                 sub eax, edi
// 007bc23d  c1f803               sar eax, 3
// 007bc240  bfffffff1f           mov edi, 0x1fffffff
// 007bc245  2bf8                 sub edi, eax
// 007bc247  3bfb                 cmp edi, ebx
// 007bc249  7305                 jae 0x7bc250
// 007bc24b  e8105fc8ff           call 0x442160
// 007bc250  03c3                 add eax, ebx
// 007bc252  3bc8                 cmp ecx, eax
// 007bc254  0f8358010000         jae 0x7bc3b2
// 007bc25a  8bd1                 mov edx, ecx
// 007bc25c  d1ea                 shr edx, 1
// 007bc25e  bfffffff1f           mov edi, 0x1fffffff
// 007bc263  2bfa                 sub edi, edx
// 007bc265  3bf9                 cmp edi, ecx
// 007bc267  730c                 jae 0x7bc275
// 007bc269  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 007bc270  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007bc273  eb05                 jmp 0x7bc27a
// 007bc275  03ca                 add ecx, edx
// 007bc277  894dec               mov dword ptr [ebp - 0x14], ecx
// 007bc27a  3bc8                 cmp ecx, eax
// 007bc27c  7305                 jae 0x7bc283
// 007bc27e  8945ec               mov dword ptr [ebp - 0x14], eax
// 007bc281  8bc8                 mov ecx, eax
// 007bc283  6a00                 push 0
// 007bc285  51                   push ecx
// 007bc286  e845f8dbff           call 0x57bad0
// 007bc28b  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 007bc28e  2b7e0c               sub edi, dword ptr [esi + 0xc]
// 007bc291  33c9                 xor ecx, ecx
// 007bc293  83c408               add esp, 8
// 007bc296  894de4               mov dword ptr [ebp - 0x1c], ecx
// 007bc299  894dfc               mov dword ptr [ebp - 4], ecx
// 007bc29c  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 007bc29f  51                   push ecx
// 007bc2a0  c1ff03               sar edi, 3
// 007bc2a3  53                   push ebx
// 007bc2a4  8d14f8               lea edx, [eax + edi*8]
// 007bc2a7  52                   push edx
// 007bc2a8  8bce                 mov ecx, esi
// 007bc2aa  8945e8               mov dword ptr [ebp - 0x18], eax
// 007bc2ad  897ddc               mov dword ptr [ebp - 0x24], edi
// 007bc2b0  e86b25f1ff           call 0x6ce820
// 007bc2b5  8b460c               mov eax, dword ptr [esi + 0xc]
// 007bc2b8  c6451400             mov byte ptr [ebp + 0x14], 0
// 007bc2bc  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007bc2bf  52                   push edx
// 007bc2c0  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007bc2c3  52                   push edx
// 007bc2c4  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007bc2c7  8d4e08               lea ecx, [esi + 8]
// 007bc2ca  51                   push ecx
// 007bc2cb  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 007bc2ce  51                   push ecx
// 007bc2cf  52                   push edx
// 007bc2d0  50                   push eax
// 007bc2d1  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 007bc2d8  e84312faff           call 0x75d520
// 007bc2dd  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 007bc2e0  8b4610               mov eax, dword ptr [esi + 0x10]
// 007bc2e3  83c418               add esp, 0x18
// 007bc2e6  c6451400             mov byte ptr [ebp + 0x14], 0
// 007bc2ea  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007bc2ed  52                   push edx
// 007bc2ee  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007bc2f1  03fb                 add edi, ebx
// 007bc2f3  52                   push edx
// 007bc2f4  8d0cf9               lea ecx, [ecx + edi*8]
// 007bc2f7  8d7e08               lea edi, [esi + 8]
// 007bc2fa  57                   push edi
// 007bc2fb  51                   push ecx
// 007bc2fc  50                   push eax
// 007bc2fd  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007bc300  50                   push eax
// 007bc301  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 007bc308  e81312faff           call 0x75d520
// 007bc30d  8b460c               mov eax, dword ptr [esi + 0xc]
// 007bc310  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007bc313  2bc8                 sub ecx, eax
// 007bc315  c1f903               sar ecx, 3
// 007bc318  83c418               add esp, 0x18
// 007bc31b  03d9                 add ebx, ecx
// 007bc31d  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 007bc324  85c0                 test eax, eax
// 007bc326  741b                 je 0x7bc343
// 007bc328  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007bc32b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007bc32e  52                   push edx
// 007bc32f  57                   push edi
// 007bc330  51                   push ecx
// 007bc331  50                   push eax
// 007bc332  e87909f8ff           call 0x73ccb0
// 007bc337  8b560c               mov edx, dword ptr [esi + 0xc]
// 007bc33a  52                   push edx
// 007bc33b  e81a750300           call 0x7f385a
// 007bc340  83c414               add esp, 0x14
// 007bc343  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 007bc346  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007bc349  8d14c8               lea edx, [eax + ecx*8]
// 007bc34c  8d0cd8               lea ecx, [eax + ebx*8]
// 007bc34f  895614               mov dword ptr [esi + 0x14], edx
// 007bc352  894e10               mov dword ptr [esi + 0x10], ecx
// 007bc355  89460c               mov dword ptr [esi + 0xc], eax
// 007bc358  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 007bc35b  64890d00000000       mov dword ptr fs:[0], ecx
// 007bc362  5f                   pop edi
// 007bc363  5e                   pop esi
// 007bc364  5b                   pop ebx
// 007bc365  8be5                 mov esp, ebp
// 007bc367  5d                   pop ebp
// 007bc368  c21000               ret 0x10
// library templates-boost-1_34_1/vector_wp.cpp (function ?_Insert_n@?$vector@V?$weak_ptr@UT@@@boost@@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@std@@IAEXV?$_Vector_const_iterator@V?$weak_ptr@UT@@@boost@@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@2@IABV?$weak_ptr@UT@@@boost@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_wp.cpp
