// from server: 100% by auto
// roc 2008-06 0069e1e0  unit: Ogre::RbxSceneManager  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0069e1e0
//
// 0069e1e0  8b442404             mov eax, dword ptr [esp + 4]
// 0069e1e4  56                   push esi
// 0069e1e5  50                   push eax
// 0069e1e6  e815fbffff           call 0x69dd00
// 0069e1eb  8bf0                 mov esi, eax
// 0069e1ed  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0069e1f0  8b5104               mov edx, dword ptr [ecx + 4]
// 0069e1f3  52                   push edx
// 0069e1f4  8bce                 mov ecx, esi
// 0069e1f6  e87557ffff           call 0x693970
// 0069e1fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0069e1fe  894004               mov dword ptr [eax + 4], eax
// 0069e201  8b4618               mov eax, dword ptr [esi + 0x18]
// 0069e204  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0069e20b  8900                 mov dword ptr [eax], eax
// 0069e20d  8b7618               mov esi, dword ptr [esi + 0x18]
// 0069e210  897608               mov dword ptr [esi + 8], esi
// 0069e213  5e                   pop esi
// 0069e214  c20400               ret 4
// library ogre-1.4.9/OgreSceneManager.cpp (function ?extractAllMovableObjectsByType@SceneManager@Ogre@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
