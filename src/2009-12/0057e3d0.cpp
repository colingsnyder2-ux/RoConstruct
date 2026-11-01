// from server: 100% by auto
// roc 2009-12 0057e3d0  unit: Ogre::RbxSceneUpdater  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057e3d0
//
// 0057e3d0  56                   push esi
// 0057e3d1  8bf1                 mov esi, ecx
// 0057e3d3  8b4630               mov eax, dword ptr [esi + 0x30]
// 0057e3d6  85c0                 test eax, eax
// 0057e3d8  7409                 je 0x57e3e3
// 0057e3da  50                   push eax
// 0057e3db  e87a542700           call 0x7f385a
// 0057e3e0  83c404               add esp, 4
// 0057e3e3  8b4624               mov eax, dword ptr [esi + 0x24]
// 0057e3e6  50                   push eax
// 0057e3e7  c7463000000000       mov dword ptr [esi + 0x30], 0
// 0057e3ee  c7463400000000       mov dword ptr [esi + 0x34], 0
// 0057e3f5  c7463800000000       mov dword ptr [esi + 0x38], 0
// 0057e3fc  e859542700           call 0x7f385a
// 0057e401  83c404               add esp, 4
// 0057e404  8d4e08               lea ecx, [esi + 8]
// 0057e407  5e                   pop esi
// 0057e408  e9f3ecffff           jmp 0x57d100
// library ogre-1.7.0/OgreResourceManager.cpp (function ??1?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
