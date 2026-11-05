// from server: 100% by auto
// roc 2010-06 00793000  unit: RBX::CircleRadialNormal  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00793000
//
// 00793000  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00793004  8b542408             mov edx, dword ptr [esp + 8]
// 00793008  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0079300c  3bca                 cmp ecx, edx
// 0079300e  7418                 je 0x793028
// 00793010  85c0                 test eax, eax
// 00793012  740a                 je 0x79301e
// 00793014  d901                 fld dword ptr [ecx]
// 00793016  d918                 fstp dword ptr [eax]
// 00793018  d94104               fld dword ptr [ecx + 4]
// 0079301b  d95804               fstp dword ptr [eax + 4]
// 0079301e  83c108               add ecx, 8
// 00793021  83c008               add eax, 8
// 00793024  3bca                 cmp ecx, edx
// 00793026  75e8                 jne 0x793010
// 00793028  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_copy@PAVVector2@Ogre@@PAV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAPAVVector2@Ogre@@PAV12@00AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
