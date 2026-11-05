// from server: 100% by auto
// roc 2010-06 00952a10  unit: seg_00950000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00952a10
//
// 00952a10  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00952a14  8b542408             mov edx, dword ptr [esp + 8]
// 00952a18  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00952a1c  3bca                 cmp ecx, edx
// 00952a1e  741e                 je 0x952a3e
// 00952a20  85c0                 test eax, eax
// 00952a22  7410                 je 0x952a34
// 00952a24  d901                 fld dword ptr [ecx]
// 00952a26  d918                 fstp dword ptr [eax]
// 00952a28  d94104               fld dword ptr [ecx + 4]
// 00952a2b  d95804               fstp dword ptr [eax + 4]
// 00952a2e  d94108               fld dword ptr [ecx + 8]
// 00952a31  d95808               fstp dword ptr [eax + 8]
// 00952a34  83c10c               add ecx, 0xc
// 00952a37  83c00c               add eax, 0xc
// 00952a3a  3bca                 cmp ecx, edx
// 00952a3c  75e2                 jne 0x952a20
// 00952a3e  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??$_Uninit_copy@PBVVector3@Ogre@@PAV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAPAVVector3@Ogre@@PBV12@0PAV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
