// from server: 100% by auto
// roc 2010-06 00975960  unit: RBX::RightAngleRampBuilder  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975960
//
// 00975960  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00975964  85c9                 test ecx, ecx
// 00975966  762a                 jbe 0x975992
// 00975968  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0097596c  8b442404             mov eax, dword ptr [esp + 4]
// 00975970  85c0                 test eax, eax
// 00975972  7416                 je 0x97598a
// 00975974  d902                 fld dword ptr [edx]
// 00975976  d918                 fstp dword ptr [eax]
// 00975978  d94204               fld dword ptr [edx + 4]
// 0097597b  d95804               fstp dword ptr [eax + 4]
// 0097597e  d94208               fld dword ptr [edx + 8]
// 00975981  d95808               fstp dword ptr [eax + 8]
// 00975984  d9420c               fld dword ptr [edx + 0xc]
// 00975987  d9580c               fstp dword ptr [eax + 0xc]
// 0097598a  49                   dec ecx
// 0097598b  83c010               add eax, 0x10
// 0097598e  85c9                 test ecx, ecx
// 00975990  77de                 ja 0x975970
// 00975992  c3                   ret 
// library ogre-1.6.4/OgreBillboardSet.cpp (function ??$_Uninit_fill_n@PAU?$TRect@M@Ogre@@IU12@V?$allocator@U?$TRect@M@Ogre@@@std@@@std@@YAXPAU?$TRect@M@Ogre@@IABU12@AAV?$allocator@U?$TRect@M@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardSet.cpp
