// from server: 100% by auto
// roc 2009-06 0047b010  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047b010
//
// 0047b010  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0047b014  8b542408             mov edx, dword ptr [esp + 8]
// 0047b018  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0047b01c  3bca                 cmp ecx, edx
// 0047b01e  741e                 je 0x47b03e
// 0047b020  85c0                 test eax, eax
// 0047b022  7410                 je 0x47b034
// 0047b024  d901                 fld dword ptr [ecx]
// 0047b026  d918                 fstp dword ptr [eax]
// 0047b028  d94104               fld dword ptr [ecx + 4]
// 0047b02b  d95804               fstp dword ptr [eax + 4]
// 0047b02e  d94108               fld dword ptr [ecx + 8]
// 0047b031  d95808               fstp dword ptr [eax + 8]
// 0047b034  83c10c               add ecx, 0xc
// 0047b037  83c00c               add eax, 0xc
// 0047b03a  3bca                 cmp ecx, edx
// 0047b03c  75e2                 jne 0x47b020
// 0047b03e  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??$_Uninit_copy@PBVVector3@Ogre@@PAV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAPAVVector3@Ogre@@PBV12@0PAV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
