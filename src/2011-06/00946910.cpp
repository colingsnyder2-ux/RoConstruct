// from server: 100% by auto
// roc 2011-06 00946910  unit: Ogre::RbxSubEntity  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00946910
//
// 00946910  8b01                 mov eax, dword ptr [ecx]
// 00946912  8b5010               mov edx, dword ptr [eax + 0x10]
// 00946915  6a00                 push 0
// 00946917  ffd2                 call edx
// 00946919  c3                   ret 
// library ogre-1.6.4/OgreMovableObject.cpp (function ?getLightCapBounds@MovableObject@Ogre@@UBEABVAxisAlignedBox@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreMovableObject.cpp
