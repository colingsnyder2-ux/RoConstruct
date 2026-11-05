// from server: 100% by auto
// roc 2008-06 0068e1a0  unit: Ogre::VRbxSky::?$SharedPtr  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068e1a0
//
// 0068e1a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068e1a4  56                   push esi
// 0068e1a5  8b742408             mov esi, dword ptr [esp + 8]
// 0068e1a9  57                   push edi
// 0068e1aa  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0068e1ae  3bf7                 cmp esi, edi
// 0068e1b0  7443                 je 0x68e1f5
// 0068e1b2  8d4814               lea ecx, [eax + 0x14]
// 0068e1b5  8d5614               lea edx, [esi + 0x14]
// 0068e1b8  53                   push ebx
// 0068e1b9  8da42400000000       lea esp, [esp]
// 0068e1c0  85c0                 test eax, eax
// 0068e1c2  7420                 je 0x68e1e4
// 0068e1c4  8b1e                 mov ebx, dword ptr [esi]
// 0068e1c6  8918                 mov dword ptr [eax], ebx
// 0068e1c8  8b5af0               mov ebx, dword ptr [edx - 0x10]
// 0068e1cb  8959f0               mov dword ptr [ecx - 0x10], ebx
// 0068e1ce  d942f4               fld dword ptr [edx - 0xc]
// 0068e1d1  d959f4               fstp dword ptr [ecx - 0xc]
// 0068e1d4  d942f8               fld dword ptr [edx - 8]
// 0068e1d7  d959f8               fstp dword ptr [ecx - 8]
// 0068e1da  d942fc               fld dword ptr [edx - 4]
// 0068e1dd  d959fc               fstp dword ptr [ecx - 4]
// 0068e1e0  d902                 fld dword ptr [edx]
// 0068e1e2  d919                 fstp dword ptr [ecx]
// 0068e1e4  83c618               add esi, 0x18
// 0068e1e7  83c018               add eax, 0x18
// 0068e1ea  83c118               add ecx, 0x18
// 0068e1ed  83c218               add edx, 0x18
// 0068e1f0  3bf7                 cmp esi, edi
// 0068e1f2  75cc                 jne 0x68e1c0
// 0068e1f4  5b                   pop ebx
// 0068e1f5  5f                   pop edi
// 0068e1f6  5e                   pop esi
// 0068e1f7  c3                   ret 
// library ogre-1.4.9/OgreAutoParamDataSource.cpp (function ??$_Uninit_copy@PBULightInfo@SceneManager@Ogre@@PAU123@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@YAPAULightInfo@SceneManager@Ogre@@PBU123@0PAU123@AAV?$allocator@ULightInfo@SceneManager@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAutoParamDataSource.cpp
