// from server: 100% by auto
// roc 2010-06 008e3f30  unit: Ogre::RbxSubEntity  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e3f30
//
// 008e3f30  8b01                 mov eax, dword ptr [ecx]
// 008e3f32  8b5010               mov edx, dword ptr [eax + 0x10]
// 008e3f35  6a00                 push 0
// 008e3f37  ffd2                 call edx
// 008e3f39  c3                   ret 
// library ogre-1.6.4/OgreMovableObject.cpp (function ?getLightCapBounds@MovableObject@Ogre@@UBEABVAxisAlignedBox@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreMovableObject.cpp
