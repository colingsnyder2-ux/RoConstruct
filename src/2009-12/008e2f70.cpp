// from server: 100% by auto
// roc 2009-12 008e2f70  unit: CXTShadowHook  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e2f70
//
// 008e2f70  33c0                 xor eax, eax
// 008e2f72  394138               cmp dword ptr [ecx + 0x38], eax
// 008e2f75  0f95c0               setne al
// 008e2f78  c3                   ret 
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?hasNamedParameters@GpuProgramParameters@Ogre@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
