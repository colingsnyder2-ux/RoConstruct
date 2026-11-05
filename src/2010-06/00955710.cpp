// from server: 100% by auto
// roc 2010-06 00955710  unit: seg_00950000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955710
//
// 00955710  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00955714  85c9                 test ecx, ecx
// 00955716  7624                 jbe 0x95573c
// 00955718  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0095571c  8b442404             mov eax, dword ptr [esp + 4]
// 00955720  85c0                 test eax, eax
// 00955722  7410                 je 0x955734
// 00955724  d902                 fld dword ptr [edx]
// 00955726  d918                 fstp dword ptr [eax]
// 00955728  d94204               fld dword ptr [edx + 4]
// 0095572b  d95804               fstp dword ptr [eax + 4]
// 0095572e  d94208               fld dword ptr [edx + 8]
// 00955731  d95808               fstp dword ptr [eax + 8]
// 00955734  49                   dec ecx
// 00955735  83c00c               add eax, 0xc
// 00955738  85c9                 test ecx, ecx
// 0095573a  77e4                 ja 0x955720
// 0095573c  c3                   ret 
// library ogre-1.4.9/OgreMeshSerializerImpl.cpp (function ??$_Uninit_fill_n@PAVVector3@Ogre@@IV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAXPAVVector3@Ogre@@IABV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMeshSerializerImpl.cpp
