// from server: 100% by auto
// roc 2007-03 005d1390  unit: seg_005d0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005d1390
//
// 005d1390  33c0                 xor eax, eax
// 005d1392  3981a4010000         cmp dword ptr [ecx + 0x1a4], eax
// 005d1398  0f95c0               setne al
// 005d139b  c3                   ret 
// library ogre-1.6.4/OgreAnimation.cpp (function ?sharesSkeletonInstance@Entity@Ogre@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAnimation.cpp
