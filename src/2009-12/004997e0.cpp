// from server: 100% by auto
// roc 2009-12 004997e0  unit: Ogre::RbxSceneManagerFactory  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004997e0
//
// 004997e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004997e4  85c9                 test ecx, ecx
// 004997e6  7412                 je 0x4997fa
// 004997e8  8b01                 mov eax, dword ptr [ecx]
// 004997ea  8b90c8000000         mov edx, dword ptr [eax + 0xc8]
// 004997f0  c744240401000000     mov dword ptr [esp + 4], 1
// 004997f8  ffe2                 jmp edx
// 004997fa  c20400               ret 4
// library ogre-1.6.4/OgreSceneManagerEnumerator.cpp (function ?destroyInstance@DefaultSceneManagerFactory@Ogre@@UAEXPAVSceneManager@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreSceneManagerEnumerator.cpp
