// from server: 100% by auto
// roc 2010-06 0062c460  unit: RBX::VInstance::?$NonFactoryProduct  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062c460
//
// 0062c460  55                   push ebp
// 0062c461  8bec                 mov ebp, esp
// 0062c463  6aff                 push -1
// 0062c465  6831b79900           push 0x99b731
// 0062c46a  64a100000000         mov eax, dword ptr fs:[0]
// 0062c470  50                   push eax
// 0062c471  64892500000000       mov dword ptr fs:[0], esp
// 0062c478  83ec08               sub esp, 8
// 0062c47b  53                   push ebx
// 0062c47c  56                   push esi
// 0062c47d  57                   push edi
// 0062c47e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0062c481  6a34                 push 0x34
// 0062c483  e818b51700           call 0x7a79a0
// 0062c488  8bf0                 mov esi, eax
// 0062c48a  83c404               add esp, 4
// 0062c48d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0062c490  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0062c497  85f6                 test esi, esi
// 0062c499  7405                 je 0x62c4a0
// 0062c49b  8b4508               mov eax, dword ptr [ebp + 8]
// 0062c49e  8906                 mov dword ptr [esi], eax
// 0062c4a0  8d4604               lea eax, [esi + 4]
// 0062c4a3  85c0                 test eax, eax
// 0062c4a5  7405                 je 0x62c4ac
// 0062c4a7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0062c4aa  8908                 mov dword ptr [eax], ecx
// 0062c4ac  8d4e08               lea ecx, [esi + 8]
// 0062c4af  894d08               mov dword ptr [ebp + 8], ecx
// 0062c4b2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 0062c4b5  c645fc01             mov byte ptr [ebp - 4], 1
// 0062c4b9  85c9                 test ecx, ecx
// 0062c4bb  7409                 je 0x62c4c6
// 0062c4bd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0062c4c0  52                   push edx
// 0062c4c1  e8baf2ffff           call 0x62b780
// 0062c4c6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0062c4c9  5f                   pop edi
// 0062c4ca  8bc6                 mov eax, esi
// 0062c4cc  5e                   pop esi
// 0062c4cd  64890d00000000       mov dword ptr fs:[0], ecx
// 0062c4d4  5b                   pop ebx
// 0062c4d5  8be5                 mov esp, ebp
// 0062c4d7  5d                   pop ebp
// 0062c4d8  c20c00               ret 0xc
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@@2@PAU342@0ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
