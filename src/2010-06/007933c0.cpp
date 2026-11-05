// from server: 100% by auto
// roc 2010-06 007933c0  unit: RBX::CircleRadialNormal  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007933c0
//
// 007933c0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007933c4  85c9                 test ecx, ecx
// 007933c6  761e                 jbe 0x7933e6
// 007933c8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007933cc  8b442404             mov eax, dword ptr [esp + 4]
// 007933d0  85c0                 test eax, eax
// 007933d2  740a                 je 0x7933de
// 007933d4  d902                 fld dword ptr [edx]
// 007933d6  d918                 fstp dword ptr [eax]
// 007933d8  d94204               fld dword ptr [edx + 4]
// 007933db  d95804               fstp dword ptr [eax + 4]
// 007933de  49                   dec ecx
// 007933df  83c008               add eax, 8
// 007933e2  85c9                 test ecx, ecx
// 007933e4  77ea                 ja 0x7933d0
// 007933e6  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_fill_n@PAVVector2@Ogre@@IV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAXPAVVector2@Ogre@@IABV12@AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
