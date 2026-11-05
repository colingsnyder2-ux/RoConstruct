// from server: 100% by auto
// roc 2011-06 0053f530  unit: G3D::MemoryManager  size: 359 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f530
//
// 0053f530  6aff                 push -1
// 0053f532  6849ec9d00           push 0x9dec49
// 0053f537  64a100000000         mov eax, dword ptr fs:[0]
// 0053f53d  50                   push eax
// 0053f53e  64892500000000       mov dword ptr fs:[0], esp
// 0053f545  51                   push ecx
// 0053f546  55                   push ebp
// 0053f547  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0053f54b  56                   push esi
// 0053f54c  8bf1                 mov esi, ecx
// 0053f54e  8b4604               mov eax, dword ptr [esi + 4]
// 0053f551  89742408             mov dword ptr [esp + 8], esi
// 0053f555  3bc5                 cmp eax, ebp
// 0053f557  0f8427010000         je 0x53f684
// 0053f55d  53                   push ebx
// 0053f55e  8bd8                 mov ebx, eax
// 0053f560  3beb                 cmp ebp, ebx
// 0053f562  57                   push edi
// 0053f563  895c2424             mov dword ptr [esp + 0x24], ebx
// 0053f567  896e04               mov dword ptr [esi + 4], ebp
// 0053f56a  7d2a                 jge 0x53f596
// 0053f56c  8d3ced00000000       lea edi, [ebp*8]
// 0053f573  2bfd                 sub edi, ebp
// 0053f575  03ff                 add edi, edi
// 0053f577  03ff                 add edi, edi
// 0053f579  2bdd                 sub ebx, ebp
// 0053f57b  eb03                 jmp 0x53f580
// 0053f57d  8d4900               lea ecx, [ecx]
// 0053f580  8b0e                 mov ecx, dword ptr [esi]
// 0053f582  03cf                 add ecx, edi
// 0053f584  ff15d004a400         call dword ptr [0xa404d0]
// 0053f58a  83c71c               add edi, 0x1c
// 0053f58d  83eb01               sub ebx, 1
// 0053f590  75ee                 jne 0x53f580
// 0053f592  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0053f596  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053f599  8b5608               mov edx, dword ptr [esi + 8]
// 0053f59c  3bca                 cmp ecx, edx
// 0053f59e  7e6a                 jle 0x53f60a
// 0053f5a0  85d2                 test edx, edx
// 0053f5a2  7509                 jne 0x53f5ad
// 0053f5a4  896e08               mov dword ptr [esi + 8], ebp
// 0053f5a7  53                   push ebx
// 0053f5a8  e986000000           jmp 0x53f633
// 0053f5ad  bf0a000000           mov edi, 0xa
// 0053f5b2  3bcf                 cmp ecx, edi
// 0053f5b4  7c4e                 jl 0x53f604
// 0053f5b6  f30f1005746ea700     movss xmm0, dword ptr [0xa76e74]
// 0053f5be  8d04d500000000       lea eax, [edx*8]
// 0053f5c5  2bc2                 sub eax, edx
// 0053f5c7  03c0                 add eax, eax
// 0053f5c9  03c0                 add eax, eax
// 0053f5cb  3d801a0600           cmp eax, 0x61a80
// 0053f5d0  7e0a                 jle 0x53f5dc
// 0053f5d2  f30f1005948aa700     movss xmm0, dword ptr [0xa78a94]
// 0053f5da  eb0f                 jmp 0x53f5eb
// 0053f5dc  3d00fa0000           cmp eax, 0xfa00
// 0053f5e1  7e08                 jle 0x53f5eb
// 0053f5e3  f30f1005ec5ca700     movss xmm0, dword ptr [0xa75cec]
// 0053f5eb  8bc2                 mov eax, edx
// 0053f5ed  f30f2ac8             cvtsi2ss xmm1, eax
// 0053f5f1  f30f59c8             mulss xmm1, xmm0
// 0053f5f5  f30f2cd1             cvttss2si edx, xmm1
// 0053f5f9  2bd0                 sub edx, eax
// 0053f5fb  03ca                 add ecx, edx
// 0053f5fd  3bcf                 cmp ecx, edi
// 0053f5ff  894e08               mov dword ptr [esi + 8], ecx
// 0053f602  7d03                 jge 0x53f607
// 0053f604  897e08               mov dword ptr [esi + 8], edi
// 0053f607  53                   push ebx
// 0053f608  eb29                 jmp 0x53f633
// 0053f60a  b856555555           mov eax, 0x55555556
// 0053f60f  f7ea                 imul edx
// 0053f611  8bc2                 mov eax, edx
// 0053f613  c1e81f               shr eax, 0x1f
// 0053f616  03c2                 add eax, edx
// 0053f618  3bc8                 cmp ecx, eax
// 0053f61a  7f1e                 jg 0x53f63a
// 0053f61c  807c242800           cmp byte ptr [esp + 0x28], 0
// 0053f621  7417                 je 0x53f63a
// 0053f623  83f90a               cmp ecx, 0xa
// 0053f626  7e12                 jle 0x53f63a
// 0053f628  8b442424             mov eax, dword ptr [esp + 0x24]
// 0053f62c  3bc8                 cmp ecx, eax
// 0053f62e  7c02                 jl 0x53f632
// 0053f630  8bc8                 mov ecx, eax
// 0053f632  51                   push ecx
// 0053f633  8bce                 mov ecx, esi
// 0053f635  e816fcffff           call 0x53f250
// 0053f63a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0053f63e  3b7e04               cmp edi, dword ptr [esi + 4]
// 0053f641  897c2428             mov dword ptr [esp + 0x28], edi
// 0053f645  7d3b                 jge 0x53f682
// 0053f647  83cbff               or ebx, 0xffffffff
// 0053f64a  8d9b00000000         lea ebx, [ebx]
// 0053f650  8b16                 mov edx, dword ptr [esi]
// 0053f652  8d0cfd00000000       lea ecx, [edi*8]
// 0053f659  2bcf                 sub ecx, edi
// 0053f65b  8d0c8a               lea ecx, [edx + ecx*4]
// 0053f65e  894c2424             mov dword ptr [esp + 0x24], ecx
// 0053f662  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0053f66a  85c9                 test ecx, ecx
// 0053f66c  7406                 je 0x53f674
// 0053f66e  ff15bc04a400         call dword ptr [0xa404bc]
// 0053f674  47                   inc edi
// 0053f675  3b7e04               cmp edi, dword ptr [esi + 4]
// 0053f678  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0053f67c  897c2428             mov dword ptr [esp + 0x28], edi
// 0053f680  7cce                 jl 0x53f650
// 0053f682  5f                   pop edi
// 0053f683  5b                   pop ebx
// 0053f684  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0053f688  5e                   pop esi
// 0053f689  5d                   pop ebp
// 0053f68a  64890d00000000       mov dword ptr fs:[0], ecx
// 0053f691  83c410               add esp, 0x10
// 0053f694  c20800               ret 8
// library rbx2016-g3d/stringutils.cpp (function ?resize@?$Array@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d stringutils.cpp
