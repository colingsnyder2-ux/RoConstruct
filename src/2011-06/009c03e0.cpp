// from server: 100% by auto
// roc 2011-06 009c03e0  unit: RBX::WedgeBuilder  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009c03e0
//
// 009c03e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009c03e4  8b542408             mov edx, dword ptr [esp + 8]
// 009c03e8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009c03ec  3bca                 cmp ecx, edx
// 009c03ee  7424                 je 0x9c0414
// 009c03f0  85c0                 test eax, eax
// 009c03f2  7416                 je 0x9c040a
// 009c03f4  d901                 fld dword ptr [ecx]
// 009c03f6  d918                 fstp dword ptr [eax]
// 009c03f8  d94104               fld dword ptr [ecx + 4]
// 009c03fb  d95804               fstp dword ptr [eax + 4]
// 009c03fe  d94108               fld dword ptr [ecx + 8]
// 009c0401  d95808               fstp dword ptr [eax + 8]
// 009c0404  d9410c               fld dword ptr [ecx + 0xc]
// 009c0407  d9580c               fstp dword ptr [eax + 0xc]
// 009c040a  83c110               add ecx, 0x10
// 009c040d  83c010               add eax, 0x10
// 009c0410  3bca                 cmp ecx, edx
// 009c0412  75dc                 jne 0x9c03f0
// 009c0414  c3                   ret 
// library ogre-1.6.4/OgreBillboard.cpp (function ??$_Uninit_copy@PBU?$TRect@M@Ogre@@PAU12@V?$allocator@U?$TRect@M@Ogre@@@std@@@std@@YAPAU?$TRect@M@Ogre@@PBU12@0PAU12@AAV?$allocator@U?$TRect@M@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboard.cpp
