// from server: 100% by auto
// roc 2008-06 0069e110  unit: Ogre::RbxSceneManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0069e110
//
// 0069e110  8b442408             mov eax, dword ptr [esp + 8]
// 0069e114  56                   push esi
// 0069e115  50                   push eax
// 0069e116  e8e5fbffff           call 0x69dd00
// 0069e11b  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0069e11e  8b10                 mov edx, dword ptr [eax]
// 0069e120  8b442408             mov eax, dword ptr [esp + 8]
// 0069e124  8b31                 mov esi, dword ptr [ecx]
// 0069e126  897004               mov dword ptr [eax + 4], esi
// 0069e129  8910                 mov dword ptr [eax], edx
// 0069e12b  895008               mov dword ptr [eax + 8], edx
// 0069e12e  89480c               mov dword ptr [eax + 0xc], ecx
// 0069e131  5e                   pop esi
// 0069e132  c20800               ret 8
// library ogre-1.4.9/OgreSceneManager.cpp (function ?getMovableObjectIterator@SceneManager@Ogre@@UAE?AV?$MapIterator@V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVMovableObject@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVMovableObject@Ogre@@@std@@@2@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
