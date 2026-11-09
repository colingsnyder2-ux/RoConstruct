// from server: 100% by auto
// roc 2008-06 0068ea50  unit: Ogre::RbxSceneManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068ea50
//
// 0068ea50  33c0                 xor eax, eax
// 0068ea52  3981148a0000         cmp dword ptr [ecx + 0x8a14], eax
// 0068ea58  0f95c0               setne al
// 0068ea5b  c3                   ret 
// library ogre-1.4.9/OgreAutoParamDataSource.cpp (function ?isShadowTechniqueInUse@SceneManager@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAutoParamDataSource.cpp
