// from server: 100% by auto
// roc 2010-06 00962d70  unit: Ogre::RbxSceneUpdater  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00962d70
//
// 00962d70  56                   push esi
// 00962d71  8bf1                 mov esi, ecx
// 00962d73  8b4630               mov eax, dword ptr [esi + 0x30]
// 00962d76  85c0                 test eax, eax
// 00962d78  7409                 je 0x962d83
// 00962d7a  50                   push eax
// 00962d7b  e81a4ce4ff           call 0x7a799a
// 00962d80  83c404               add esp, 4
// 00962d83  8b4624               mov eax, dword ptr [esi + 0x24]
// 00962d86  50                   push eax
// 00962d87  c7463000000000       mov dword ptr [esi + 0x30], 0
// 00962d8e  c7463400000000       mov dword ptr [esi + 0x34], 0
// 00962d95  c7463800000000       mov dword ptr [esi + 0x38], 0
// 00962d9c  e8f94be4ff           call 0x7a799a
// 00962da1  83c404               add esp, 4
// 00962da4  8d4e08               lea ecx, [esi + 8]
// 00962da7  5e                   pop esi
// 00962da8  e933ecffff           jmp 0x9619e0
// library ogre-1.7.0/OgreResourceManager.cpp (function ??1?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
