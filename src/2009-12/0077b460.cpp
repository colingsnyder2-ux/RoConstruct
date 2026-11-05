// from server: 100% by auto
// roc 2009-12 0077b460  unit: RBX::BallBallContact  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0077b460
//
// 0077b460  33c0                 xor eax, eax
// 0077b462  394134               cmp dword ptr [ecx + 0x34], eax
// 0077b465  0f95c0               setne al
// 0077b468  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ?isLightCapSeparate@ShadowRenderable@Ogre@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
