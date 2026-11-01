// from server: 100% by auto
// roc 2009-06 004736d0  unit: Ogre::RbxSceneManagerFactory  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004736d0
//
// 004736d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004736d4  85c9                 test ecx, ecx
// 004736d6  7412                 je 0x4736ea
// 004736d8  8b01                 mov eax, dword ptr [ecx]
// 004736da  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 004736e0  c744240401000000     mov dword ptr [esp + 4], 1
// 004736e8  ffe2                 jmp edx
// 004736ea  c20400               ret 4
// library ogre-1.4.9/OgreSceneManagerEnumerator.cpp (function ?destroyInstance@DefaultSceneManagerFactory@Ogre@@UAEXPAVSceneManager@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManagerEnumerator.cpp
