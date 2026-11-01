// from server: 100% by auto
// roc 2009-12 0048fd20  unit: Ogre::RbxSubEntity  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048fd20
//
// 0048fd20  8b01                 mov eax, dword ptr [ecx]
// 0048fd22  8b5010               mov edx, dword ptr [eax + 0x10]
// 0048fd25  6a00                 push 0
// 0048fd27  ffd2                 call edx
// 0048fd29  c3                   ret 
// library ogre-1.6.4/OgreMovableObject.cpp (function ?getLightCapBounds@MovableObject@Ogre@@UBEABVAxisAlignedBox@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreMovableObject.cpp
