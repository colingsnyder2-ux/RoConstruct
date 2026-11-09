// from server: 100% by auto
// roc 2008-06 00690250  unit: Ogre::RbxSceneManagerFactory  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00690250
//
// 00690250  56                   push esi
// 00690251  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00690255  85f6                 test esi, esi
// 00690257  763d                 jbe 0x690296
// 00690259  8b542408             mov edx, dword ptr [esp + 8]
// 0069025d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00690261  8d4214               lea eax, [edx + 0x14]
// 00690264  57                   push edi
// 00690265  85d2                 test edx, edx
// 00690267  7421                 je 0x69028a
// 00690269  8b39                 mov edi, dword ptr [ecx]
// 0069026b  893a                 mov dword ptr [edx], edi
// 0069026d  8b7904               mov edi, dword ptr [ecx + 4]
// 00690270  8978f0               mov dword ptr [eax - 0x10], edi
// 00690273  d94108               fld dword ptr [ecx + 8]
// 00690276  d958f4               fstp dword ptr [eax - 0xc]
// 00690279  d9410c               fld dword ptr [ecx + 0xc]
// 0069027c  d958f8               fstp dword ptr [eax - 8]
// 0069027f  d94110               fld dword ptr [ecx + 0x10]
// 00690282  d958fc               fstp dword ptr [eax - 4]
// 00690285  d94114               fld dword ptr [ecx + 0x14]
// 00690288  d918                 fstp dword ptr [eax]
// 0069028a  4e                   dec esi
// 0069028b  83c218               add edx, 0x18
// 0069028e  83c018               add eax, 0x18
// 00690291  85f6                 test esi, esi
// 00690293  77d0                 ja 0x690265
// 00690295  5f                   pop edi
// 00690296  5e                   pop esi
// 00690297  c3                   ret 
// library ogre-1.4.9/OgreSceneManager.cpp (function ??$_Uninit_fill_n@PAULightInfo@SceneManager@Ogre@@IU123@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@YAXPAULightInfo@SceneManager@Ogre@@IABU123@AAV?$allocator@ULightInfo@SceneManager@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
