// roc 2012-06 006231e0  unit: RBX::WedgeBuilder  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006231e0
//
// 006231e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006231e4  8b542408             mov edx, dword ptr [esp + 8]
// 006231e8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006231ec  3bca                 cmp ecx, edx
// 006231ee  7418                 je 0x623208
// 006231f0  85c0                 test eax, eax
// 006231f2  740a                 je 0x6231fe
// 006231f4  d901                 fld dword ptr [ecx]
// 006231f6  d918                 fstp dword ptr [eax]
// 006231f8  d94104               fld dword ptr [ecx + 4]
// 006231fb  d95804               fstp dword ptr [eax + 4]
// 006231fe  83c108               add ecx, 8
// 00623201  83c008               add eax, 8
// 00623204  3bca                 cmp ecx, edx
// 00623206  75e8                 jne 0x6231f0
// 00623208  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_copy@PAVVector2@Ogre@@PAV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAPAVVector2@Ogre@@PAV12@00AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
