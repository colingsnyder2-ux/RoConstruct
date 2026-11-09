// from server: 100% by auto
// roc 2008-06 004dc670  unit: RBX::ViewNew::ViewG3D  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc670
//
// 004dc670  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004dc674  8b542408             mov edx, dword ptr [esp + 8]
// 004dc678  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004dc67c  3bca                 cmp ecx, edx
// 004dc67e  741e                 je 0x4dc69e
// 004dc680  85c0                 test eax, eax
// 004dc682  7410                 je 0x4dc694
// 004dc684  d901                 fld dword ptr [ecx]
// 004dc686  d918                 fstp dword ptr [eax]
// 004dc688  d94104               fld dword ptr [ecx + 4]
// 004dc68b  d95804               fstp dword ptr [eax + 4]
// 004dc68e  d94108               fld dword ptr [ecx + 8]
// 004dc691  d95808               fstp dword ptr [eax + 8]
// 004dc694  83c10c               add ecx, 0xc
// 004dc697  83c00c               add eax, 0xc
// 004dc69a  3bca                 cmp ecx, edx
// 004dc69c  75e2                 jne 0x4dc680
// 004dc69e  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??$_Uninit_copy@PBVVector3@Ogre@@PAV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAPAVVector3@Ogre@@PBV12@0PAV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
