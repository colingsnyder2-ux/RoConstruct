// from server: 100% by auto
// roc 2009-06 00486430  unit: Ogre::RbxMeshPartAdapter  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486430
//
// 00486430  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00486434  85c9                 test ecx, ecx
// 00486436  761e                 jbe 0x486456
// 00486438  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0048643c  8b442404             mov eax, dword ptr [esp + 4]
// 00486440  85c0                 test eax, eax
// 00486442  740a                 je 0x48644e
// 00486444  d902                 fld dword ptr [edx]
// 00486446  d918                 fstp dword ptr [eax]
// 00486448  d94204               fld dword ptr [edx + 4]
// 0048644b  d95804               fstp dword ptr [eax + 4]
// 0048644e  49                   dec ecx
// 0048644f  83c008               add eax, 8
// 00486452  85c9                 test ecx, ecx
// 00486454  77ea                 ja 0x486440
// 00486456  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_fill_n@PAVVector2@Ogre@@IV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAXPAVVector2@Ogre@@IABV12@AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
