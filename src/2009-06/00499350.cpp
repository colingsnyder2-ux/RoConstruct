// from server: 100% by auto
// roc 2009-06 00499350  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00499350
//
// 00499350  56                   push esi
// 00499351  57                   push edi
// 00499352  8bf9                 mov edi, ecx
// 00499354  8b7704               mov esi, dword ptr [edi + 4]
// 00499357  85f6                 test esi, esi
// 00499359  7410                 je 0x49936b
// 0049935b  8bce                 mov ecx, esi
// 0049935d  e87efaffff           call 0x498de0
// 00499362  56                   push esi
// 00499363  e8caf62700           call 0x718a32
// 00499368  83c404               add esp, 4
// 0049936b  8b4708               mov eax, dword ptr [edi + 8]
// 0049936e  50                   push eax
// 0049936f  e8bef62700           call 0x718a32
// 00499374  83c404               add esp, 4
// 00499377  5f                   pop edi
// 00499378  5e                   pop esi
// 00499379  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ?destroy@?$SharedPtr@VGpuProgramParameters@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
