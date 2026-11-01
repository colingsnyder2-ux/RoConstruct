// from server: 100% by auto
// roc 2011-06 009c0450  unit: RBX::WedgeBuilder  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009c0450
//
// 009c0450  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009c0454  85c9                 test ecx, ecx
// 009c0456  762a                 jbe 0x9c0482
// 009c0458  8b54240c             mov edx, dword ptr [esp + 0xc]
// 009c045c  8b442404             mov eax, dword ptr [esp + 4]
// 009c0460  85c0                 test eax, eax
// 009c0462  7416                 je 0x9c047a
// 009c0464  d902                 fld dword ptr [edx]
// 009c0466  d918                 fstp dword ptr [eax]
// 009c0468  d94204               fld dword ptr [edx + 4]
// 009c046b  d95804               fstp dword ptr [eax + 4]
// 009c046e  d94208               fld dword ptr [edx + 8]
// 009c0471  d95808               fstp dword ptr [eax + 8]
// 009c0474  d9420c               fld dword ptr [edx + 0xc]
// 009c0477  d9580c               fstp dword ptr [eax + 0xc]
// 009c047a  49                   dec ecx
// 009c047b  83c010               add eax, 0x10
// 009c047e  85c9                 test ecx, ecx
// 009c0480  77de                 ja 0x9c0460
// 009c0482  c3                   ret 
// library ogre-1.6.4/OgreBillboardSet.cpp (function ??$_Uninit_fill_n@PAU?$TRect@M@Ogre@@IU12@V?$allocator@U?$TRect@M@Ogre@@@std@@@std@@YAXPAU?$TRect@M@Ogre@@IABU12@AAV?$allocator@U?$TRect@M@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardSet.cpp
