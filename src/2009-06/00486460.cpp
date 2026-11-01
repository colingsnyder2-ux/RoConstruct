// from server: 100% by auto
// roc 2009-06 00486460  unit: Ogre::RbxMeshPartAdapter  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486460
//
// 00486460  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00486464  85c9                 test ecx, ecx
// 00486466  762a                 jbe 0x486492
// 00486468  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0048646c  8b442404             mov eax, dword ptr [esp + 4]
// 00486470  85c0                 test eax, eax
// 00486472  7416                 je 0x48648a
// 00486474  d902                 fld dword ptr [edx]
// 00486476  d918                 fstp dword ptr [eax]
// 00486478  d94204               fld dword ptr [edx + 4]
// 0048647b  d95804               fstp dword ptr [eax + 4]
// 0048647e  d94208               fld dword ptr [edx + 8]
// 00486481  d95808               fstp dword ptr [eax + 8]
// 00486484  d9420c               fld dword ptr [edx + 0xc]
// 00486487  d9580c               fstp dword ptr [eax + 0xc]
// 0048648a  49                   dec ecx
// 0048648b  83c010               add eax, 0x10
// 0048648e  85c9                 test ecx, ecx
// 00486490  77de                 ja 0x486470
// 00486492  c3                   ret 
// library ogre-1.6.4/OgreBillboardSet.cpp (function ??$_Uninit_fill_n@PAU?$TRect@M@Ogre@@IU12@V?$allocator@U?$TRect@M@Ogre@@@std@@@std@@YAXPAU?$TRect@M@Ogre@@IABU12@AAV?$allocator@U?$TRect@M@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardSet.cpp
