// from server: 100% by auto
// roc 2010-06 008d9070  unit: Ogre::RbxTextureCompositorSceneManager  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d9070
//
// 008d9070  51                   push ecx
// 008d9071  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d9075  56                   push esi
// 008d9076  8b742410             mov esi, dword ptr [esp + 0x10]
// 008d907a  57                   push edi
// 008d907b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008d907f  c644240800           mov byte ptr [esp + 8], 0
// 008d9084  8b442408             mov eax, dword ptr [esp + 8]
// 008d9088  50                   push eax
// 008d9089  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d908d  52                   push edx
// 008d908e  83c108               add ecx, 8
// 008d9091  51                   push ecx
// 008d9092  50                   push eax
// 008d9093  56                   push esi
// 008d9094  57                   push edi
// 008d9095  e836f6ffff           call 0x8d86d0
// 008d909a  8d0cf6               lea ecx, [esi + esi*8]
// 008d909d  83c418               add esp, 0x18
// 008d90a0  8d04cf               lea eax, [edi + ecx*8]
// 008d90a3  5f                   pop edi
// 008d90a4  5e                   pop esi
// 008d90a5  59                   pop ecx
// 008d90a6  c20c00               ret 0xc
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Ufill@?$vector@UPMWorkingData@ProgressiveMesh@Ogre@@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@std@@IAEPAUPMWorkingData@ProgressiveMesh@Ogre@@PAU345@IABU345@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
