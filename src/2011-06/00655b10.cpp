// from server: 100% by auto
// roc 2011-06 00655b10  unit: RBX::VInstance::?$NonFactoryProduct  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00655b10
//
// 00655b10  55                   push ebp
// 00655b11  8bec                 mov ebp, esp
// 00655b13  6aff                 push -1
// 00655b15  6831cb9e00           push 0x9ecb31
// 00655b1a  64a100000000         mov eax, dword ptr fs:[0]
// 00655b20  50                   push eax
// 00655b21  64892500000000       mov dword ptr fs:[0], esp
// 00655b28  83ec08               sub esp, 8
// 00655b2b  53                   push ebx
// 00655b2c  56                   push esi
// 00655b2d  57                   push edi
// 00655b2e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00655b31  6a34                 push 0x34
// 00655b33  e826451b00           call 0x80a05e
// 00655b38  8bf0                 mov esi, eax
// 00655b3a  83c404               add esp, 4
// 00655b3d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00655b40  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00655b47  85f6                 test esi, esi
// 00655b49  7405                 je 0x655b50
// 00655b4b  8b4508               mov eax, dword ptr [ebp + 8]
// 00655b4e  8906                 mov dword ptr [esi], eax
// 00655b50  8d4604               lea eax, [esi + 4]
// 00655b53  85c0                 test eax, eax
// 00655b55  7405                 je 0x655b5c
// 00655b57  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00655b5a  8908                 mov dword ptr [eax], ecx
// 00655b5c  8d4e08               lea ecx, [esi + 8]
// 00655b5f  894d08               mov dword ptr [ebp + 8], ecx
// 00655b62  894d0c               mov dword ptr [ebp + 0xc], ecx
// 00655b65  c645fc01             mov byte ptr [ebp - 4], 1
// 00655b69  85c9                 test ecx, ecx
// 00655b6b  7409                 je 0x655b76
// 00655b6d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00655b70  52                   push edx
// 00655b71  e86aebffff           call 0x6546e0
// 00655b76  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00655b79  5f                   pop edi
// 00655b7a  8bc6                 mov eax, esi
// 00655b7c  5e                   pop esi
// 00655b7d  64890d00000000       mov dword ptr fs:[0], ecx
// 00655b84  5b                   pop ebx
// 00655b85  8be5                 mov esp, ebp
// 00655b87  5d                   pop ebp
// 00655b88  c20c00               ret 0xc
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@@2@PAU342@0ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
