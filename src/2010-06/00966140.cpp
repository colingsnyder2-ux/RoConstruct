// from server: 100% by auto
// roc 2010-06 00966140  unit: Ogre::RbxSceneUpdater  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00966140
//
// 00966140  56                   push esi
// 00966141  8bf1                 mov esi, ecx
// 00966143  8b4630               mov eax, dword ptr [esi + 0x30]
// 00966146  85c0                 test eax, eax
// 00966148  7409                 je 0x966153
// 0096614a  50                   push eax
// 0096614b  e84a18e4ff           call 0x7a799a
// 00966150  83c404               add esp, 4
// 00966153  8b4624               mov eax, dword ptr [esi + 0x24]
// 00966156  50                   push eax
// 00966157  c7463000000000       mov dword ptr [esi + 0x30], 0
// 0096615e  c7463400000000       mov dword ptr [esi + 0x34], 0
// 00966165  c7463800000000       mov dword ptr [esi + 0x38], 0
// 0096616c  e82918e4ff           call 0x7a799a
// 00966171  83c404               add esp, 4
// 00966174  8d4e08               lea ecx, [esi + 8]
// 00966177  5e                   pop esi
// 00966178  e9b3efffff           jmp 0x965130
// library ogre-1.7.0/OgreResourceManager.cpp (function ??1?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
