// from server: 100% by auto
// roc 2011-06 006cf5c0  unit: RBX::Mechanism  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006cf5c0
//
// 006cf5c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006cf5c4  8b542408             mov edx, dword ptr [esp + 8]
// 006cf5c8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006cf5cc  3bca                 cmp ecx, edx
// 006cf5ce  7418                 je 0x6cf5e8
// 006cf5d0  85c0                 test eax, eax
// 006cf5d2  740a                 je 0x6cf5de
// 006cf5d4  d901                 fld dword ptr [ecx]
// 006cf5d6  d918                 fstp dword ptr [eax]
// 006cf5d8  d94104               fld dword ptr [ecx + 4]
// 006cf5db  d95804               fstp dword ptr [eax + 4]
// 006cf5de  83c108               add ecx, 8
// 006cf5e1  83c008               add eax, 8
// 006cf5e4  3bca                 cmp ecx, edx
// 006cf5e6  75e8                 jne 0x6cf5d0
// 006cf5e8  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_copy@PAVVector2@Ogre@@PAV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAPAVVector2@Ogre@@PAV12@00AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
