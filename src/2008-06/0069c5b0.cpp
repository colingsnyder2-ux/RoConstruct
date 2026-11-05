// from server: 100% by auto
// roc 2008-06 0069c5b0  unit: Ogre::RbxSceneManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0069c5b0
//
// 0069c5b0  8d442404             lea eax, [esp + 4]
// 0069c5b4  50                   push eax
// 0069c5b5  81c1f4420000         add ecx, 0x42f4
// 0069c5bb  e8e04dd8ff           call 0x4213a0
// 0069c5c0  c20400               ret 4
// library ogre-1.4.9/OgreSceneManager.cpp (function ?addRenderQueueListener@SceneManager@Ogre@@UAEXPAVRenderQueueListener@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
