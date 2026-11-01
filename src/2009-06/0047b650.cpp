// from server: 100% by auto
// roc 2009-06 0047b650  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047b650
//
// 0047b650  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0047b654  85c9                 test ecx, ecx
// 0047b656  7624                 jbe 0x47b67c
// 0047b658  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0047b65c  8b442404             mov eax, dword ptr [esp + 4]
// 0047b660  85c0                 test eax, eax
// 0047b662  7410                 je 0x47b674
// 0047b664  d902                 fld dword ptr [edx]
// 0047b666  d918                 fstp dword ptr [eax]
// 0047b668  d94204               fld dword ptr [edx + 4]
// 0047b66b  d95804               fstp dword ptr [eax + 4]
// 0047b66e  d94208               fld dword ptr [edx + 8]
// 0047b671  d95808               fstp dword ptr [eax + 8]
// 0047b674  49                   dec ecx
// 0047b675  83c00c               add eax, 0xc
// 0047b678  85c9                 test ecx, ecx
// 0047b67a  77e4                 ja 0x47b660
// 0047b67c  c3                   ret 
// library ogre-1.4.9/OgreMeshSerializerImpl.cpp (function ??$_Uninit_fill_n@PAVVector3@Ogre@@IV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAXPAVVector3@Ogre@@IABV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMeshSerializerImpl.cpp
