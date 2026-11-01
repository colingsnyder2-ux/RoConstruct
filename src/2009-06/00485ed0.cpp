// from server: 100% by auto
// roc 2009-06 00485ed0  unit: Ogre::RbxMeshPartAdapter  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00485ed0
//
// 00485ed0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00485ed4  8b542408             mov edx, dword ptr [esp + 8]
// 00485ed8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00485edc  3bca                 cmp ecx, edx
// 00485ede  7424                 je 0x485f04
// 00485ee0  85c0                 test eax, eax
// 00485ee2  7416                 je 0x485efa
// 00485ee4  d901                 fld dword ptr [ecx]
// 00485ee6  d918                 fstp dword ptr [eax]
// 00485ee8  d94104               fld dword ptr [ecx + 4]
// 00485eeb  d95804               fstp dword ptr [eax + 4]
// 00485eee  d94108               fld dword ptr [ecx + 8]
// 00485ef1  d95808               fstp dword ptr [eax + 8]
// 00485ef4  d9410c               fld dword ptr [ecx + 0xc]
// 00485ef7  d9580c               fstp dword ptr [eax + 0xc]
// 00485efa  83c110               add ecx, 0x10
// 00485efd  83c010               add eax, 0x10
// 00485f00  3bca                 cmp ecx, edx
// 00485f02  75dc                 jne 0x485ee0
// 00485f04  c3                   ret 
// library ogre-1.6.4/OgreBillboard.cpp (function ??$_Uninit_copy@PBU?$TRect@M@Ogre@@PAU12@V?$allocator@U?$TRect@M@Ogre@@@std@@@std@@YAPAU?$TRect@M@Ogre@@PBU12@0PAU12@AAV?$allocator@U?$TRect@M@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboard.cpp
