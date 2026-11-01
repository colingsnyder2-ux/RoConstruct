// from server: 100% by auto
// roc 2010-06 008d9b70  unit: Ogre::RbxTextureCompositorSceneManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d9b70
//
// 008d9b70  53                   push ebx
// 008d9b71  8bd9                 mov ebx, ecx
// 008d9b73  56                   push esi
// 008d9b74  8b730c               mov esi, dword ptr [ebx + 0xc]
// 008d9b77  85f6                 test esi, esi
// 008d9b79  7423                 je 0x8d9b9e
// 008d9b7b  57                   push edi
// 008d9b7c  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 008d9b7f  3bf7                 cmp esi, edi
// 008d9b81  740e                 je 0x8d9b91
// 008d9b83  8bce                 mov ecx, esi
// 008d9b85  e816d6ffff           call 0x8d71a0
// 008d9b8a  83c648               add esi, 0x48
// 008d9b8d  3bf7                 cmp esi, edi
// 008d9b8f  75f2                 jne 0x8d9b83
// 008d9b91  8b430c               mov eax, dword ptr [ebx + 0xc]
// 008d9b94  50                   push eax
// 008d9b95  e800deecff           call 0x7a799a
// 008d9b9a  83c404               add esp, 4
// 008d9b9d  5f                   pop edi
// 008d9b9e  5e                   pop esi
// 008d9b9f  c7430c00000000       mov dword ptr [ebx + 0xc], 0
// 008d9ba6  c7431000000000       mov dword ptr [ebx + 0x10], 0
// 008d9bad  c7431400000000       mov dword ptr [ebx + 0x14], 0
// 008d9bb4  5b                   pop ebx
// 008d9bb5  c3                   ret 
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Tidy@?$vector@UPMWorkingData@ProgressiveMesh@Ogre@@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
