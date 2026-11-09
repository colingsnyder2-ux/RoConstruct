// from server: 100% by auto
// roc 2009-12 005b06e0  unit: seg_005b0000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b06e0
//
// 005b06e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b06e4  85c9                 test ecx, ecx
// 005b06e6  7624                 jbe 0x5b070c
// 005b06e8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005b06ec  8b442404             mov eax, dword ptr [esp + 4]
// 005b06f0  85c0                 test eax, eax
// 005b06f2  7410                 je 0x5b0704
// 005b06f4  d902                 fld dword ptr [edx]
// 005b06f6  d918                 fstp dword ptr [eax]
// 005b06f8  d94204               fld dword ptr [edx + 4]
// 005b06fb  d95804               fstp dword ptr [eax + 4]
// 005b06fe  d94208               fld dword ptr [edx + 8]
// 005b0701  d95808               fstp dword ptr [eax + 8]
// 005b0704  49                   dec ecx
// 005b0705  83c00c               add eax, 0xc
// 005b0708  85c9                 test ecx, ecx
// 005b070a  77e4                 ja 0x5b06f0
// 005b070c  c3                   ret 
// library ogre-1.4.9/OgreMeshSerializerImpl.cpp (function ??$_Uninit_fill_n@PAVVector3@Ogre@@IV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAXPAVVector3@Ogre@@IABV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMeshSerializerImpl.cpp
