// from server: 100% by auto
// roc 2007-08 00492ea0  unit: RBX::Network::Players  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00492ea0
//
// 00492ea0  55                   push ebp
// 00492ea1  8bec                 mov ebp, esp
// 00492ea3  6aff                 push -1
// 00492ea5  68407e7400           push 0x747e40
// 00492eaa  64a100000000         mov eax, dword ptr fs:[0]
// 00492eb0  50                   push eax
// 00492eb1  83ec08               sub esp, 8
// 00492eb4  53                   push ebx
// 00492eb5  56                   push esi
// 00492eb6  57                   push edi
// 00492eb7  a188518b00           mov eax, dword ptr [0x8b5188]
// 00492ebc  33c5                 xor eax, ebp
// 00492ebe  50                   push eax
// 00492ebf  8d45f4               lea eax, [ebp - 0xc]
// 00492ec2  64a300000000         mov dword ptr fs:[0], eax
// 00492ec8  8965f0               mov dword ptr [ebp - 0x10], esp
// 00492ecb  6a34                 push 0x34
// 00492ecd  e824d01900           call 0x62fef6
// 00492ed2  8bf0                 mov esi, eax
// 00492ed4  83c404               add esp, 4
// 00492ed7  85f6                 test esi, esi
// 00492ed9  8975ec               mov dword ptr [ebp - 0x14], esi
// 00492edc  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00492ee3  7405                 je 0x492eea
// 00492ee5  8b4508               mov eax, dword ptr [ebp + 8]
// 00492ee8  8906                 mov dword ptr [esi], eax
// 00492eea  8d4604               lea eax, [esi + 4]
// 00492eed  85c0                 test eax, eax
// 00492eef  7405                 je 0x492ef6
// 00492ef1  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00492ef4  8908                 mov dword ptr [eax], ecx
// 00492ef6  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00492ef9  52                   push edx
// 00492efa  8d4608               lea eax, [esi + 8]
// 00492efd  50                   push eax
// 00492efe  e86decffff           call 0x491b70
// 00492f03  83c408               add esp, 8
// 00492f06  8bc6                 mov eax, esi
// 00492f08  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00492f0b  64890d00000000       mov dword ptr fs:[0], ecx
// 00492f12  59                   pop ecx
// 00492f13  5f                   pop edi
// 00492f14  5e                   pop esi
// 00492f15  5b                   pop ebx
// 00492f16  8be5                 mov esp, ebp
// 00492f18  5d                   pop ebp
// 00492f19  c20c00               ret 0xc
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@@2@PAU342@0ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
