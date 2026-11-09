// roc 2012-06 006232b0  unit: RBX::WedgeBuilder  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006232b0
//
// 006232b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006232b4  85c9                 test ecx, ecx
// 006232b6  761e                 jbe 0x6232d6
// 006232b8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006232bc  8b442404             mov eax, dword ptr [esp + 4]
// 006232c0  85c0                 test eax, eax
// 006232c2  740a                 je 0x6232ce
// 006232c4  d902                 fld dword ptr [edx]
// 006232c6  d918                 fstp dword ptr [eax]
// 006232c8  d94204               fld dword ptr [edx + 4]
// 006232cb  d95804               fstp dword ptr [eax + 4]
// 006232ce  49                   dec ecx
// 006232cf  83c008               add eax, 8
// 006232d2  85c9                 test ecx, ecx
// 006232d4  77ea                 ja 0x6232c0
// 006232d6  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_fill_n@PAVVector2@Ogre@@IV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAXPAVVector2@Ogre@@IABV12@AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
