// from server: 100% by auto
// roc 2010-06 008d90b0  unit: Ogre::RbxTextureCompositorSceneManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d90b0
//
// 008d90b0  56                   push esi
// 008d90b1  8b742408             mov esi, dword ptr [esp + 8]
// 008d90b5  57                   push edi
// 008d90b6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008d90ba  3bf7                 cmp esi, edi
// 008d90bc  7410                 je 0x8d90ce
// 008d90be  8bff                 mov edi, edi
// 008d90c0  8bce                 mov ecx, esi
// 008d90c2  e8d9e0ffff           call 0x8d71a0
// 008d90c7  83c648               add esi, 0x48
// 008d90ca  3bf7                 cmp esi, edi
// 008d90cc  75f2                 jne 0x8d90c0
// 008d90ce  5f                   pop edi
// 008d90cf  5e                   pop esi
// 008d90d0  c20800               ret 8
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Destroy@?$vector@UPMWorkingData@ProgressiveMesh@Ogre@@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@std@@IAEXPAUPMWorkingData@ProgressiveMesh@Ogre@@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
