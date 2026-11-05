// from server: 100% by auto
// roc 2009-06 006fa550  unit: RBX::GroupDragTool  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fa550
//
// 006fa550  53                   push ebx
// 006fa551  56                   push esi
// 006fa552  e8f9feffff           call 0x6fa450
// 006fa557  8b03                 mov eax, dword ptr [ebx]
// 006fa559  8d48ff               lea ecx, [eax - 1]
// 006fa55c  83c408               add esp, 8
// 006fa55f  83f90b               cmp ecx, 0xb
// 006fa562  0f87c2000000         ja 0x6fa62a
// 006fa568  ff248d2ca66f00       jmp dword ptr [ecx*4 + 0x6fa62c]
// 006fa56f  6a01                 push 1
// 006fa571  57                   push edi
// 006fa572  56                   push esi
// 006fa573  e848fdffff           call 0x6fa2c0
// 006fa578  83c40c               add esp, 0xc
// 006fa57b  897b08               mov dword ptr [ebx + 8], edi
// 006fa57e  c7030c000000         mov dword ptr [ebx], 0xc
// 006fa584  c3                   ret 
// 006fa585  33c9                 xor ecx, ecx
// 006fa587  83f802               cmp eax, 2
// 006fa58a  0f94c1               sete cl
// 006fa58d  6a00                 push 0
// 006fa58f  51                   push ecx
// 006fa590  57                   push edi
// 006fa591  6a02                 push 2
// 006fa593  56                   push esi
// 006fa594  e837fcffff           call 0x6fa1d0
// 006fa599  83c414               add esp, 0x14
// 006fa59c  897b08               mov dword ptr [ebx + 8], edi
// 006fa59f  c7030c000000         mov dword ptr [ebx], 0xc
// 006fa5a5  c3                   ret 
// 006fa5a6  8b5308               mov edx, dword ptr [ebx + 8]
// 006fa5a9  52                   push edx
// 006fa5aa  57                   push edi
// 006fa5ab  6a01                 push 1
// 006fa5ad  56                   push esi
// 006fa5ae  e84dfcffff           call 0x6fa200
// 006fa5b3  83c410               add esp, 0x10
// 006fa5b6  897b08               mov dword ptr [ebx + 8], edi
// 006fa5b9  c7030c000000         mov dword ptr [ebx], 0xc
// 006fa5bf  c3                   ret 
// 006fa5c0  dd4308               fld qword ptr [ebx + 8]
// 006fa5c3  83ec08               sub esp, 8
// 006fa5c6  dd1c24               fstp qword ptr [esp]
// 006fa5c9  56                   push esi
// 006fa5ca  e8e1f8ffff           call 0x6f9eb0
// 006fa5cf  50                   push eax
// 006fa5d0  57                   push edi
// 006fa5d1  6a01                 push 1
// 006fa5d3  56                   push esi
// 006fa5d4  e827fcffff           call 0x6fa200
// 006fa5d9  83c41c               add esp, 0x1c
// 006fa5dc  897b08               mov dword ptr [ebx + 8], edi
// 006fa5df  c7030c000000         mov dword ptr [ebx], 0xc
// 006fa5e5  c3                   ret 
// 006fa5e6  8b0e                 mov ecx, dword ptr [esi]
// 006fa5e8  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006fa5eb  8b4308               mov eax, dword ptr [ebx + 8]
// 006fa5ee  8bcf                 mov ecx, edi
// 006fa5f0  c1e106               shl ecx, 6
// 006fa5f3  330c82               xor ecx, dword ptr [edx + eax*4]
// 006fa5f6  8d0482               lea eax, [edx + eax*4]
// 006fa5f9  81e1c03f0000         and ecx, 0x3fc0
// 006fa5ff  3108                 xor dword ptr [eax], ecx
// 006fa601  897b08               mov dword ptr [ebx + 8], edi
// 006fa604  c7030c000000         mov dword ptr [ebx], 0xc
// 006fa60a  c3                   ret 
// 006fa60b  8b4308               mov eax, dword ptr [ebx + 8]
// 006fa60e  3bf8                 cmp edi, eax
// 006fa610  740f                 je 0x6fa621
// 006fa612  6a00                 push 0
// 006fa614  50                   push eax
// 006fa615  57                   push edi
// 006fa616  6a00                 push 0
// 006fa618  56                   push esi
// 006fa619  e8b2fbffff           call 0x6fa1d0
// 006fa61e  83c414               add esp, 0x14
// 006fa621  897b08               mov dword ptr [ebx + 8], edi
// 006fa624  c7030c000000         mov dword ptr [ebx], 0xc
// 006fa62a  c3                   ret 
// 006fa62b  90                   nop 
// 006fa62c  6f                   outsd dx, dword ptr [esi]
// 006fa62d  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa62e  6f                   outsd dx, dword ptr [esi]
// 006fa62f  0085a56f0085         add byte ptr [ebp - 0x7aff905b], al
// 006fa635  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa636  6f                   outsd dx, dword ptr [esi]
// 006fa637  00a6a56f00c0         add byte ptr [esi - 0x3fff905b], ah
// 006fa63d  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa63e  6f                   outsd dx, dword ptr [esi]
// 006fa63f  002a                 add byte ptr [edx], ch
// 006fa641  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 006fa642  6f                   outsd dx, dword ptr [esi]
// 006fa643  002a                 add byte ptr [edx], ch
// 006fa645  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 006fa646  6f                   outsd dx, dword ptr [esi]
// 006fa647  002a                 add byte ptr [edx], ch
// 006fa649  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 006fa64a  6f                   outsd dx, dword ptr [esi]
// 006fa64b  002a                 add byte ptr [edx], ch
// 006fa64d  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 006fa64e  6f                   outsd dx, dword ptr [esi]
// 006fa64f  002a                 add byte ptr [edx], ch
// 006fa651  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 006fa652  6f                   outsd dx, dword ptr [esi]
// 006fa653  00e6                 add dh, ah
// 006fa655  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa656  6f                   outsd dx, dword ptr [esi]
// 006fa657  000b                 add byte ptr [ebx], cl
// 006fa659  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 006fa65a  6f                   outsd dx, dword ptr [esi]
// library lua-5.1/lcode.c (function _discharge2reg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
