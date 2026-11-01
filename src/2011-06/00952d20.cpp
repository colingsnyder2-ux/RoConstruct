// from server: 100% by auto
// roc 2011-06 00952d20  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00952d20
//
// 00952d20  51                   push ecx
// 00952d21  8b542410             mov edx, dword ptr [esp + 0x10]
// 00952d25  56                   push esi
// 00952d26  8b742410             mov esi, dword ptr [esp + 0x10]
// 00952d2a  57                   push edi
// 00952d2b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00952d2f  c644240800           mov byte ptr [esp + 8], 0
// 00952d34  8b442408             mov eax, dword ptr [esp + 8]
// 00952d38  50                   push eax
// 00952d39  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00952d3d  52                   push edx
// 00952d3e  51                   push ecx
// 00952d3f  50                   push eax
// 00952d40  56                   push esi
// 00952d41  57                   push edi
// 00952d42  e8e9feffff           call 0x952c30
// 00952d47  8d0cf6               lea ecx, [esi + esi*8]
// 00952d4a  83c418               add esp, 0x18
// 00952d4d  8d048f               lea eax, [edi + ecx*4]
// 00952d50  5f                   pop edi
// 00952d51  5e                   pop esi
// 00952d52  59                   pop ecx
// 00952d53  c20c00               ret 0xc
// library ogre-1.7.0/OgreSubMesh.cpp (function ?_Ufill@?$vector@UCluster@Ogre@@V?$allocator@UCluster@Ogre@@@std@@@std@@IAEPAUCluster@Ogre@@PAU34@IABU34@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSubMesh.cpp
