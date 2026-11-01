// from server: 100% by auto
// roc 2010-06 00752de0  unit: RBX::PrismPoly  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00752de0
//
// 00752de0  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00752de3  2b4110               sub eax, dword ptr [ecx + 0x10]
// 00752de6  c1f802               sar eax, 2
// 00752de9  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ?getNumKeyFrames@AnimationTrack@Ogre@@UBEGXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
