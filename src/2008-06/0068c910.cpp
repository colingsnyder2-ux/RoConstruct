// from server: 100% by auto
// roc 2008-06 0068c910  unit: Ogre::RbxSceneManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068c910
//
// 0068c910  d9442404             fld dword ptr [esp + 4]
// 0068c914  d991e48a0000         fst dword ptr [ecx + 0x8ae4]
// 0068c91a  dcc8                 fmul st(0), st(0)
// 0068c91c  d999e88a0000         fstp dword ptr [ecx + 0x8ae8]
// 0068c922  c20400               ret 4
// library ogre-1.4.9/OgreSceneManager.cpp (function ?setShadowFarDistance@SceneManager@Ogre@@UAEXM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
