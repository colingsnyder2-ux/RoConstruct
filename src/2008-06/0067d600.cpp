// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0067d600  unit: Ogre::RbxEntity  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067d600
//
// 0067d600  55                   push ebp
// 0067d601  8bec                 mov ebp, esp
// 0067d603  6aff                 push -1
// 0067d605  6830d87d00           push 0x7dd830
// 0067d60a  64a100000000         mov eax, dword ptr fs:[0]
// 0067d610  50                   push eax
// 0067d611  64892500000000       mov dword ptr fs:[0], esp
// 0067d618  83ec28               sub esp, 0x28
// 0067d61b  53                   push ebx
// 0067d61c  56                   push esi
// 0067d61d  8bf1                 mov esi, ecx
// 0067d61f  8b560c               mov edx, dword ptr [esi + 0xc]
// 0067d622  57                   push edi
// 0067d623  8965f0               mov dword ptr [ebp - 0x10], esp
// 0067d626  85d2                 test edx, edx
// 0067d628  7504                 jne 0x67d62e
// 0067d62a  33db                 xor ebx, ebx
// 0067d62c  eb08                 jmp 0x67d636
// 0067d62e  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 0067d631  2bda                 sub ebx, edx
// 0067d633  c1fb04               sar ebx, 4
// 0067d636  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0067d639  85ff                 test edi, edi
// 0067d63b  0f84c2010000         je 0x67d803
// 0067d641  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0067d644  8bc1                 mov eax, ecx
// 0067d646  2bc2                 sub eax, edx
// 0067d648  c1f804               sar eax, 4
// 0067d64b  baffffff0f           mov edx, 0xfffffff
// 0067d650  2bd0                 sub edx, eax
// 0067d652  3bd7                 cmp edx, edi
// 0067d654  7305                 jae 0x67d65b
// 0067d656  e8e596e4ff           call 0x4c6d40
// 0067d65b  8d1438               lea edx, [eax + edi]
// 0067d65e  3bda                 cmp ebx, edx
// 0067d660  0f83d7000000         jae 0x67d73d
// 0067d666  8bc3                 mov eax, ebx
// 0067d668  d1e8                 shr eax, 1
// 0067d66a  b9ffffff0f           mov ecx, 0xfffffff
// 0067d66f  2bc8                 sub ecx, eax
// 0067d671  3bcb                 cmp ecx, ebx
// 0067d673  7304                 jae 0x67d679
// 0067d675  33db                 xor ebx, ebx
// 0067d677  eb02                 jmp 0x67d67b
// 0067d679  03d8                 add ebx, eax
// 0067d67b  3bda                 cmp ebx, edx
// 0067d67d  7302                 jae 0x67d681
// 0067d67f  8bda                 mov ebx, edx
// 0067d681  6a00                 push 0
// 0067d683  53                   push ebx
// 0067d684  e857efffff           call 0x67c5e0
// 0067d689  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0067d68c  894510               mov dword ptr [ebp + 0x10], eax
// 0067d68f  c645ec00             mov byte ptr [ebp - 0x14], 0
// 0067d693  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0067d696  50                   push eax
// 0067d697  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0067d69a  50                   push eax
// 0067d69b  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0067d69e  8d5608               lea edx, [esi + 8]
// 0067d6a1  52                   push edx
// 0067d6a2  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0067d6a5  52                   push edx
// 0067d6a6  50                   push eax
// 0067d6a7  51                   push ecx
// 0067d6a8  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0067d6af  e8dcf1ffff           call 0x67c890
// 0067d6b4  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0067d6b7  83c420               add esp, 0x20
// 0067d6ba  51                   push ecx
// 0067d6bb  57                   push edi
// 0067d6bc  50                   push eax
// 0067d6bd  8bce                 mov ecx, esi
// 0067d6bf  e89cfaffff           call 0x67d160
// 0067d6c4  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0067d6c7  c6451400             mov byte ptr [ebp + 0x14], 0
// 0067d6cb  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0067d6ce  52                   push edx
// 0067d6cf  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0067d6d2  52                   push edx
// 0067d6d3  8d5608               lea edx, [esi + 8]
// 0067d6d6  52                   push edx
// 0067d6d7  50                   push eax
// 0067d6d8  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0067d6db  51                   push ecx
// 0067d6dc  50                   push eax
// 0067d6dd  e8aef1ffff           call 0x67c890
// 0067d6e2  8b460c               mov eax, dword ptr [esi + 0xc]
// 0067d6e5  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0067d6e8  2bc8                 sub ecx, eax
// 0067d6ea  c1f904               sar ecx, 4
// 0067d6ed  83c418               add esp, 0x18
// 0067d6f0  03f9                 add edi, ecx
// 0067d6f2  85c0                 test eax, eax
// 0067d6f4  7409                 je 0x67d6ff
// 0067d6f6  50                   push eax
// 0067d6f7  e87e2f0200           call 0x6a067a
// 0067d6fc  83c404               add esp, 4
// 0067d6ff  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0067d702  c1e304               shl ebx, 4
// 0067d705  03d8                 add ebx, eax
// 0067d707  c1e704               shl edi, 4
// 0067d70a  03f8                 add edi, eax
// 0067d70c  895e14               mov dword ptr [esi + 0x14], ebx
// 0067d70f  897e10               mov dword ptr [esi + 0x10], edi
// 0067d712  89460c               mov dword ptr [esi + 0xc], eax
// 0067d715  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0067d718  64890d00000000       mov dword ptr fs:[0], ecx
// 0067d71f  5f                   pop edi
// 0067d720  5e                   pop esi
// 0067d721  5b                   pop ebx
// 0067d722  8be5                 mov esp, ebp
// 0067d724  5d                   pop ebp
// 0067d725  c21000               ret 0x10
// library ogre-1.7.0/OgreRenderSystem.cpp (function ?_Insert_n@?$vector@VPlane@Ogre@@V?$allocator@VPlane@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@VPlane@Ogre@@V?$allocator@VPlane@Ogre@@@std@@@2@IABVPlane@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreRenderSystem.cpp
