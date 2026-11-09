// from server: 100% by auto
// roc 2009-06 00485ea0  unit: Ogre::RbxMeshPartAdapter  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00485ea0
//
// 00485ea0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00485ea4  8b542408             mov edx, dword ptr [esp + 8]
// 00485ea8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00485eac  3bca                 cmp ecx, edx
// 00485eae  7418                 je 0x485ec8
// 00485eb0  85c0                 test eax, eax
// 00485eb2  740a                 je 0x485ebe
// 00485eb4  d901                 fld dword ptr [ecx]
// 00485eb6  d918                 fstp dword ptr [eax]
// 00485eb8  d94104               fld dword ptr [ecx + 4]
// 00485ebb  d95804               fstp dword ptr [eax + 4]
// 00485ebe  83c108               add ecx, 8
// 00485ec1  83c008               add eax, 8
// 00485ec4  3bca                 cmp ecx, edx
// 00485ec6  75e8                 jne 0x485eb0
// 00485ec8  c3                   ret 
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Uninit_copy@PAVVector2@Ogre@@PAV12@V?$allocator@VVector2@Ogre@@@std@@@std@@YAPAVVector2@Ogre@@PAV12@00AAV?$allocator@VVector2@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
