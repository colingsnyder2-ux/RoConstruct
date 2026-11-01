// from server: 100% by auto
// roc 2009-12 007dfba0  unit: RBX::CircleRadialNormal  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dfba0
//
// 007dfba0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dfba4  8b542408             mov edx, dword ptr [esp + 8]
// 007dfba8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dfbac  3bca                 cmp ecx, edx
// 007dfbae  7418                 je 0x7dfbc8
// 007dfbb0  85c0                 test eax, eax
// 007dfbb2  740a                 je 0x7dfbbe
// 007dfbb4  d901                 fld dword ptr [ecx]
// 007dfbb6  d918                 fstp dword ptr [eax]
// 007dfbb8  d94104               fld dword ptr [ecx + 4]
// 007dfbbb  d95804               fstp dword ptr [eax + 4]
// 007dfbbe  83c108               add ecx, 8
// 007dfbc1  83c008               add eax, 8
// 007dfbc4  3bca                 cmp ecx, edx
// 007dfbc6  75e8                 jne 0x7dfbb0
// 007dfbc8  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_copy@PAVVector2@Ogre@@PAV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAPAVVector2@Ogre@@PAV12@00AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
