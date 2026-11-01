// from server: 100% by auto
// roc 2011-06 006cfc20  unit: RBX::Mechanism  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006cfc20
//
// 006cfc20  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cfc24  85c9                 test ecx, ecx
// 006cfc26  761e                 jbe 0x6cfc46
// 006cfc28  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006cfc2c  8b442404             mov eax, dword ptr [esp + 4]
// 006cfc30  85c0                 test eax, eax
// 006cfc32  740a                 je 0x6cfc3e
// 006cfc34  d902                 fld dword ptr [edx]
// 006cfc36  d918                 fstp dword ptr [eax]
// 006cfc38  d94204               fld dword ptr [edx + 4]
// 006cfc3b  d95804               fstp dword ptr [eax + 4]
// 006cfc3e  49                   dec ecx
// 006cfc3f  83c008               add eax, 8
// 006cfc42  85c9                 test ecx, ecx
// 006cfc44  77ea                 ja 0x6cfc30
// 006cfc46  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_fill_n@PAVVector2@Ogre@@IV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAXPAVVector2@Ogre@@IABV12@AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
