// from server: 100% by auto
// roc 2009-12 007ade20  unit: RBX::HUMAN::HumanoidState  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ade20
//
// 007ade20  d905d8749d00         fld dword ptr [0x9d74d8]
// 007ade26  c3                   ret 
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?getBoundingRadius@MovablePlane@Ogre@@UBEMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
