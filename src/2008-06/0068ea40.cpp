// from server: 100% by auto
// roc 2008-06 0068ea40  unit: Ogre::RbxSceneManager  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068ea40
//
// 0068ea40  8b81148a0000         mov eax, dword ptr [ecx + 0x8a14]
// 0068ea46  c1e802               shr eax, 2
// 0068ea49  83e001               and eax, 1
// 0068ea4c  c3                   ret 
// library ogre-1.4.9/OgreAutoParamDataSource.cpp (function ?isShadowTechniqueIntegrated@SceneManager@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAutoParamDataSource.cpp
