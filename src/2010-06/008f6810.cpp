// from server: 100% by auto
// roc 2010-06 008f6810  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6810
//
// 008f6810  51                   push ecx
// 008f6811  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6815  56                   push esi
// 008f6816  8b742410             mov esi, dword ptr [esp + 0x10]
// 008f681a  57                   push edi
// 008f681b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f681f  c644240800           mov byte ptr [esp + 8], 0
// 008f6824  8b442408             mov eax, dword ptr [esp + 8]
// 008f6828  50                   push eax
// 008f6829  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f682d  52                   push edx
// 008f682e  83c108               add ecx, 8
// 008f6831  51                   push ecx
// 008f6832  50                   push eax
// 008f6833  56                   push esi
// 008f6834  57                   push edi
// 008f6835  e8c6e4ffff           call 0x8f4d00
// 008f683a  8d0cf6               lea ecx, [esi + esi*8]
// 008f683d  83c418               add esp, 0x18
// 008f6840  8d04cf               lea eax, [edi + ecx*8]
// 008f6843  5f                   pop edi
// 008f6844  5e                   pop esi
// 008f6845  59                   pop ecx
// 008f6846  c20c00               ret 0xc
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Ufill@?$vector@UPMWorkingData@ProgressiveMesh@Ogre@@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@std@@IAEPAUPMWorkingData@ProgressiveMesh@Ogre@@PAU345@IABU345@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
