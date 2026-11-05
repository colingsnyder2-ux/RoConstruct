// from server: 100% by auto
// roc 2008-06 004dca70  unit: RBX::ViewNew::ViewG3D  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dca70
//
// 004dca70  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004dca74  85c9                 test ecx, ecx
// 004dca76  7624                 jbe 0x4dca9c
// 004dca78  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004dca7c  8b442404             mov eax, dword ptr [esp + 4]
// 004dca80  85c0                 test eax, eax
// 004dca82  7410                 je 0x4dca94
// 004dca84  d902                 fld dword ptr [edx]
// 004dca86  d918                 fstp dword ptr [eax]
// 004dca88  d94204               fld dword ptr [edx + 4]
// 004dca8b  d95804               fstp dword ptr [eax + 4]
// 004dca8e  d94208               fld dword ptr [edx + 8]
// 004dca91  d95808               fstp dword ptr [eax + 8]
// 004dca94  49                   dec ecx
// 004dca95  83c00c               add eax, 0xc
// 004dca98  85c9                 test ecx, ecx
// 004dca9a  77e4                 ja 0x4dca80
// 004dca9c  c3                   ret 
// library ogre-1.4.9/OgreMeshSerializerImpl.cpp (function ??$_Uninit_fill_n@PAVVector3@Ogre@@IV12@V?$allocator@VVector3@Ogre@@@std@@@std@@YAXPAVVector3@Ogre@@IABV12@AAV?$allocator@VVector3@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMeshSerializerImpl.cpp
