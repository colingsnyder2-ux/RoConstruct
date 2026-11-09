// from server: 100% by auto
// roc 2008-06 0068ea30  unit: Ogre::RbxSceneManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068ea30
//
// 0068ea30  8b81148a0000         mov eax, dword ptr [ecx + 0x8a14]
// 0068ea36  83e001               and eax, 1
// 0068ea39  c3                   ret 
// library ogre-1.4.9/OgreAutoParamDataSource.cpp (function ?isShadowTechniqueAdditive@SceneManager@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAutoParamDataSource.cpp
