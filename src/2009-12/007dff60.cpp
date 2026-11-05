// from server: 100% by auto
// roc 2009-12 007dff60  unit: RBX::CircleRadialNormal  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dff60
//
// 007dff60  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007dff64  85c9                 test ecx, ecx
// 007dff66  761e                 jbe 0x7dff86
// 007dff68  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007dff6c  8b442404             mov eax, dword ptr [esp + 4]
// 007dff70  85c0                 test eax, eax
// 007dff72  740a                 je 0x7dff7e
// 007dff74  d902                 fld dword ptr [edx]
// 007dff76  d918                 fstp dword ptr [eax]
// 007dff78  d94204               fld dword ptr [edx + 4]
// 007dff7b  d95804               fstp dword ptr [eax + 4]
// 007dff7e  49                   dec ecx
// 007dff7f  83c008               add eax, 8
// 007dff82  85c9                 test ecx, ecx
// 007dff84  77ea                 ja 0x7dff70
// 007dff86  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_fill_n@PAVVector2@Ogre@@IV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAXPAVVector2@Ogre@@IABV12@AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
