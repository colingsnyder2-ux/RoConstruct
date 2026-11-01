// from server: 100% by auto
// roc 2010-06 0064cb50  unit: RBX::VWidget::?$NonFactoryProduct  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064cb50
//
// 0064cb50  56                   push esi
// 0064cb51  8bf1                 mov esi, ecx
// 0064cb53  8b4630               mov eax, dword ptr [esi + 0x30]
// 0064cb56  85c0                 test eax, eax
// 0064cb58  7409                 je 0x64cb63
// 0064cb5a  50                   push eax
// 0064cb5b  e83aae1500           call 0x7a799a
// 0064cb60  83c404               add esp, 4
// 0064cb63  8b4624               mov eax, dword ptr [esi + 0x24]
// 0064cb66  50                   push eax
// 0064cb67  c7463000000000       mov dword ptr [esi + 0x30], 0
// 0064cb6e  c7463400000000       mov dword ptr [esi + 0x34], 0
// 0064cb75  c7463800000000       mov dword ptr [esi + 0x38], 0
// 0064cb7c  e819ae1500           call 0x7a799a
// 0064cb81  83c404               add esp, 4
// 0064cb84  8d4e08               lea ecx, [esi + 8]
// 0064cb87  5e                   pop esi
// 0064cb88  e943feffff           jmp 0x64c9d0
// library ogre-1.7.0/OgreResourceManager.cpp (function ??1?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
