// from server: 100% by auto
// roc 2012-06 0062b430  unit: G3D::MemoryManager  size: 359 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062b430
//
// 0062b430  6aff                 push -1
// 0062b432  681946ab00           push 0xab4619
// 0062b437  64a100000000         mov eax, dword ptr fs:[0]
// 0062b43d  50                   push eax
// 0062b43e  64892500000000       mov dword ptr fs:[0], esp
// 0062b445  51                   push ecx
// 0062b446  55                   push ebp
// 0062b447  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0062b44b  56                   push esi
// 0062b44c  8bf1                 mov esi, ecx
// 0062b44e  8b4604               mov eax, dword ptr [esi + 4]
// 0062b451  89742408             mov dword ptr [esp + 8], esi
// 0062b455  3bc5                 cmp eax, ebp
// 0062b457  0f8427010000         je 0x62b584
// 0062b45d  53                   push ebx
// 0062b45e  8bd8                 mov ebx, eax
// 0062b460  3beb                 cmp ebp, ebx
// 0062b462  57                   push edi
// 0062b463  895c2424             mov dword ptr [esp + 0x24], ebx
// 0062b467  896e04               mov dword ptr [esi + 4], ebp
// 0062b46a  7d2a                 jge 0x62b496
// 0062b46c  8d3ced00000000       lea edi, [ebp*8]
// 0062b473  2bfd                 sub edi, ebp
// 0062b475  03ff                 add edi, edi
// 0062b477  03ff                 add edi, edi
// 0062b479  2bdd                 sub ebx, ebp
// 0062b47b  eb03                 jmp 0x62b480
// 0062b47d  8d4900               lea ecx, [ecx]
// 0062b480  8b0e                 mov ecx, dword ptr [esi]
// 0062b482  03cf                 add ecx, edi
// 0062b484  ff153c26b200         call dword ptr [0xb2263c]
// 0062b48a  83c71c               add edi, 0x1c
// 0062b48d  83eb01               sub ebx, 1
// 0062b490  75ee                 jne 0x62b480
// 0062b492  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0062b496  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062b499  8b5608               mov edx, dword ptr [esi + 8]
// 0062b49c  3bca                 cmp ecx, edx
// 0062b49e  7e6a                 jle 0x62b50a
// 0062b4a0  85d2                 test edx, edx
// 0062b4a2  7509                 jne 0x62b4ad
// 0062b4a4  896e08               mov dword ptr [esi + 8], ebp
// 0062b4a7  53                   push ebx
// 0062b4a8  e986000000           jmp 0x62b533
// 0062b4ad  bf0a000000           mov edi, 0xa
// 0062b4b2  3bcf                 cmp ecx, edi
// 0062b4b4  7c4e                 jl 0x62b504
// 0062b4b6  f30f1005dc48b600     movss xmm0, dword ptr [0xb648dc]
// 0062b4be  8d04d500000000       lea eax, [edx*8]
// 0062b4c5  2bc2                 sub eax, edx
// 0062b4c7  03c0                 add eax, eax
// 0062b4c9  03c0                 add eax, eax
// 0062b4cb  3d801a0600           cmp eax, 0x61a80
// 0062b4d0  7e0a                 jle 0x62b4dc
// 0062b4d2  f30f1005d848b600     movss xmm0, dword ptr [0xb648d8]
// 0062b4da  eb0f                 jmp 0x62b4eb
// 0062b4dc  3d00fa0000           cmp eax, 0xfa00
// 0062b4e1  7e08                 jle 0x62b4eb
// 0062b4e3  f30f10056832b600     movss xmm0, dword ptr [0xb63268]
// 0062b4eb  8bc2                 mov eax, edx
// 0062b4ed  f30f2ac8             cvtsi2ss xmm1, eax
// 0062b4f1  f30f59c8             mulss xmm1, xmm0
// 0062b4f5  f30f2cd1             cvttss2si edx, xmm1
// 0062b4f9  2bd0                 sub edx, eax
// 0062b4fb  03ca                 add ecx, edx
// 0062b4fd  3bcf                 cmp ecx, edi
// 0062b4ff  894e08               mov dword ptr [esi + 8], ecx
// 0062b502  7d03                 jge 0x62b507
// 0062b504  897e08               mov dword ptr [esi + 8], edi
// 0062b507  53                   push ebx
// 0062b508  eb29                 jmp 0x62b533
// 0062b50a  b856555555           mov eax, 0x55555556
// 0062b50f  f7ea                 imul edx
// 0062b511  8bc2                 mov eax, edx
// 0062b513  c1e81f               shr eax, 0x1f
// 0062b516  03c2                 add eax, edx
// 0062b518  3bc8                 cmp ecx, eax
// 0062b51a  7f1e                 jg 0x62b53a
// 0062b51c  807c242800           cmp byte ptr [esp + 0x28], 0
// 0062b521  7417                 je 0x62b53a
// 0062b523  83f90a               cmp ecx, 0xa
// 0062b526  7e12                 jle 0x62b53a
// 0062b528  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062b52c  3bc8                 cmp ecx, eax
// 0062b52e  7c02                 jl 0x62b532
// 0062b530  8bc8                 mov ecx, eax
// 0062b532  51                   push ecx
// 0062b533  8bce                 mov ecx, esi
// 0062b535  e816fcffff           call 0x62b150
// 0062b53a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0062b53e  3b7e04               cmp edi, dword ptr [esi + 4]
// 0062b541  897c2428             mov dword ptr [esp + 0x28], edi
// 0062b545  7d3b                 jge 0x62b582
// 0062b547  83cbff               or ebx, 0xffffffff
// 0062b54a  8d9b00000000         lea ebx, [ebx]
// 0062b550  8b16                 mov edx, dword ptr [esi]
// 0062b552  8d0cfd00000000       lea ecx, [edi*8]
// 0062b559  2bcf                 sub ecx, edi
// 0062b55b  8d0c8a               lea ecx, [edx + ecx*4]
// 0062b55e  894c2424             mov dword ptr [esp + 0x24], ecx
// 0062b562  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0062b56a  85c9                 test ecx, ecx
// 0062b56c  7406                 je 0x62b574
// 0062b56e  ff155426b200         call dword ptr [0xb22654]
// 0062b574  47                   inc edi
// 0062b575  3b7e04               cmp edi, dword ptr [esi + 4]
// 0062b578  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0062b57c  897c2428             mov dword ptr [esp + 0x28], edi
// 0062b580  7cce                 jl 0x62b550
// 0062b582  5f                   pop edi
// 0062b583  5b                   pop ebx
// 0062b584  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0062b588  5e                   pop esi
// 0062b589  5d                   pop ebp
// 0062b58a  64890d00000000       mov dword ptr fs:[0], ecx
// 0062b591  83c410               add esp, 0x10
// 0062b594  c20800               ret 8
// library rbx2016-g3d/stringutils.cpp (function ?resize@?$Array@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d stringutils.cpp
