// from server: 100% by auto
// roc 2009-12 005ad990  unit: seg_005a0000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005ad990
//
// 005ad990  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005ad994  8b542408             mov edx, dword ptr [esp + 8]
// 005ad998  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005ad99c  3bca                 cmp ecx, edx
// 005ad99e  741e                 je 0x5ad9be
// 005ad9a0  85c0                 test eax, eax
// 005ad9a2  7410                 je 0x5ad9b4
// 005ad9a4  d901                 fld dword ptr [ecx]
// 005ad9a6  d918                 fstp dword ptr [eax]
// 005ad9a8  d94104               fld dword ptr [ecx + 4]
// 005ad9ab  d95804               fstp dword ptr [eax + 4]
// 005ad9ae  d94108               fld dword ptr [ecx + 8]
// 005ad9b1  d95808               fstp dword ptr [eax + 8]
// 005ad9b4  83c10c               add ecx, 0xc
// 005ad9b7  83c00c               add eax, 0xc
// 005ad9ba  3bca                 cmp ecx, edx
// 005ad9bc  75e2                 jne 0x5ad9a0
// 005ad9be  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??$_Uninit_copy@PBVVector3@Ogre@@PAV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAPAVVector3@Ogre@@PBV12@0PAV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
