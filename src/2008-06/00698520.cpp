// from server: 100% by auto
// roc 2008-06 00698520  unit: Ogre::RbxSceneManager  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00698520
//
// 00698520  83ec0c               sub esp, 0xc
// 00698523  8d442410             lea eax, [esp + 0x10]
// 00698527  50                   push eax
// 00698528  8d542404             lea edx, [esp + 4]
// 0069852c  52                   push edx
// 0069852d  81c1ac010000         add ecx, 0x1ac
// 00698533  e878eaffff           call 0x696fb0
// 00698538  83c40c               add esp, 0xc
// 0069853b  c20400               ret 4
// library ogre-1.4.9/OgreSceneManager.cpp (function ?addSpecialCaseRenderQueue@SceneManager@Ogre@@UAEXE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
