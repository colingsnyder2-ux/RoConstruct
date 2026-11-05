// from server: 100% by auto
// roc 2008-06 0068ea20  unit: Ogre::RbxSceneManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068ea20
//
// 0068ea20  8b81148a0000         mov eax, dword ptr [ecx + 0x8a14]
// 0068ea26  d1e8                 shr eax, 1
// 0068ea28  83e001               and eax, 1
// 0068ea2b  c3                   ret 
// library ogre-1.4.9/OgreAutoParamDataSource.cpp (function ?isShadowTechniqueModulative@SceneManager@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAutoParamDataSource.cpp
