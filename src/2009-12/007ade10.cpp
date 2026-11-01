// from server: 100% by auto
// roc 2009-12 007ade10  unit: RBX::HUMAN::HumanoidState  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ade10
//
// 007ade10  d90580dd9e00         fld dword ptr [0x9edd80]
// 007ade16  c3                   ret 
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?getBoundingRadius@MovablePlane@Ogre@@UBEMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
