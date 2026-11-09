// from server: 100% by auto
// roc 2008-06 00698540  unit: Ogre::RbxSceneManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00698540
//
// 00698540  8d442404             lea eax, [esp + 4]
// 00698544  50                   push eax
// 00698545  81c1ac010000         add ecx, 0x1ac
// 0069854b  e850ebffff           call 0x6970a0
// 00698550  c20400               ret 4
// library ogre-1.4.9/OgreSceneManager.cpp (function ?removeSpecialCaseRenderQueue@SceneManager@Ogre@@UAEXE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
