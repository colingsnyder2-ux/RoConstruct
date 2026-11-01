// from server: 100% by auto
// roc 2009-12 005817d0  unit: Ogre::RbxSceneUpdater  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005817d0
//
// 005817d0  56                   push esi
// 005817d1  8bf1                 mov esi, ecx
// 005817d3  8b4630               mov eax, dword ptr [esi + 0x30]
// 005817d6  85c0                 test eax, eax
// 005817d8  7409                 je 0x5817e3
// 005817da  50                   push eax
// 005817db  e87a202700           call 0x7f385a
// 005817e0  83c404               add esp, 4
// 005817e3  8b4624               mov eax, dword ptr [esi + 0x24]
// 005817e6  50                   push eax
// 005817e7  c7463000000000       mov dword ptr [esi + 0x30], 0
// 005817ee  c7463400000000       mov dword ptr [esi + 0x34], 0
// 005817f5  c7463800000000       mov dword ptr [esi + 0x38], 0
// 005817fc  e859202700           call 0x7f385a
// 00581801  83c404               add esp, 4
// 00581804  8d4e08               lea ecx, [esi + 8]
// 00581807  5e                   pop esi
// 00581808  e9b3efffff           jmp 0x5807c0
// library ogre-1.7.0/OgreResourceManager.cpp (function ??1?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
