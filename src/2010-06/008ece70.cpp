// from server: 100% by auto
// roc 2010-06 008ece70  unit: Ogre::RbxSceneManagerFactory  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ece70
//
// 008ece70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ece74  85c9                 test ecx, ecx
// 008ece76  7412                 je 0x8ece8a
// 008ece78  8b01                 mov eax, dword ptr [ecx]
// 008ece7a  8b90c8000000         mov edx, dword ptr [eax + 0xc8]
// 008ece80  c744240401000000     mov dword ptr [esp + 4], 1
// 008ece88  ffe2                 jmp edx
// 008ece8a  c20400               ret 4
// library ogre-1.6.4/OgreSceneManagerEnumerator.cpp (function ?destroyInstance@DefaultSceneManagerFactory@Ogre@@UAEXPAVSceneManager@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreSceneManagerEnumerator.cpp
