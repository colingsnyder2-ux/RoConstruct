// from server: 100% by auto
// roc 2007-03 007005f0  unit: seg_00700000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007005f0
//
// 007005f0  8bc1                 mov eax, ecx
// 007005f2  33c9                 xor ecx, ecx
// 007005f4  c70018d17d00         mov dword ptr [eax], 0x7dd118
// 007005fa  894804               mov dword ptr [eax + 4], ecx
// 007005fd  894808               mov dword ptr [eax + 8], ecx
// 00700600  89480c               mov dword ptr [eax + 0xc], ecx
// 00700603  c3                   ret 
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
