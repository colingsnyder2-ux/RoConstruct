// from server: 100% by auto
// roc 2008-06 006994b0  unit: Ogre::RbxSceneManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006994b0
//
// 006994b0  83ec0c               sub esp, 0xc
// 006994b3  8d442410             lea eax, [esp + 0x10]
// 006994b7  81c1c4000000         add ecx, 0xc4
// 006994bd  807c241400           cmp byte ptr [esp + 0x14], 0
// 006994c2  50                   push eax
// 006994c3  7410                 je 0x6994d5
// 006994c5  8d542404             lea edx, [esp + 4]
// 006994c9  52                   push edx
// 006994ca  e871f7f4ff           call 0x5e8c40
// 006994cf  83c40c               add esp, 0xc
// 006994d2  c20800               ret 8
// 006994d5  e8860af5ff           call 0x5e9f60
// 006994da  83c40c               add esp, 0xc
// 006994dd  c20800               ret 8
// library ogre-1.4.9/OgreSceneManager.cpp (function ?_notifyAutotrackingSceneNode@SceneManager@Ogre@@UAEXPAVSceneNode@2@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
