// from server: 100% by auto
// roc 2010-06 009758b0  unit: RBX::RightAngleRampBuilder  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009758b0
//
// 009758b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009758b4  8b542408             mov edx, dword ptr [esp + 8]
// 009758b8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009758bc  3bca                 cmp ecx, edx
// 009758be  7424                 je 0x9758e4
// 009758c0  85c0                 test eax, eax
// 009758c2  7416                 je 0x9758da
// 009758c4  d901                 fld dword ptr [ecx]
// 009758c6  d918                 fstp dword ptr [eax]
// 009758c8  d94104               fld dword ptr [ecx + 4]
// 009758cb  d95804               fstp dword ptr [eax + 4]
// 009758ce  d94108               fld dword ptr [ecx + 8]
// 009758d1  d95808               fstp dword ptr [eax + 8]
// 009758d4  d9410c               fld dword ptr [ecx + 0xc]
// 009758d7  d9580c               fstp dword ptr [eax + 0xc]
// 009758da  83c110               add ecx, 0x10
// 009758dd  83c010               add eax, 0x10
// 009758e0  3bca                 cmp ecx, edx
// 009758e2  75dc                 jne 0x9758c0
// 009758e4  c3                   ret 
// library ogre-1.6.4/OgreBillboard.cpp (function ??$_Uninit_copy@PBU?$TRect@M@Ogre@@PAU12@V?$allocator@U?$TRect@M@Ogre@@@std@@@std@@YAPAU?$TRect@M@Ogre@@PBU12@0PAU12@AAV?$allocator@U?$TRect@M@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboard.cpp
