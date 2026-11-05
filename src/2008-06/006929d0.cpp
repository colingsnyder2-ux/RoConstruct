// from server: 100% by auto
// roc 2008-06 006929d0  unit: Ogre::RbxSceneManager  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006929d0
//
// 006929d0  8b81c4010000         mov eax, dword ptr [ecx + 0x1c4]
// 006929d6  56                   push esi
// 006929d7  8db1ac010000         lea esi, [ecx + 0x1ac]
// 006929dd  8b4804               mov ecx, dword ptr [eax + 4]
// 006929e0  51                   push ecx
// 006929e1  8bce                 mov ecx, esi
// 006929e3  e808d6ffff           call 0x68fff0
// 006929e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006929eb  894004               mov dword ptr [eax + 4], eax
// 006929ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 006929f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006929f8  8900                 mov dword ptr [eax], eax
// 006929fa  8b7618               mov esi, dword ptr [esi + 0x18]
// 006929fd  897608               mov dword ptr [esi + 8], esi
// 00692a00  5e                   pop esi
// 00692a01  c3                   ret 
// library ogre-1.4.9/OgreSceneManager.cpp (function ?clearSpecialCaseRenderQueues@SceneManager@Ogre@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
