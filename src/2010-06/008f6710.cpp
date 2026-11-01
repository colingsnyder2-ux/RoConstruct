// from server: 100% by auto
// roc 2010-06 008f6710  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6710
//
// 008f6710  51                   push ecx
// 008f6711  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6715  56                   push esi
// 008f6716  8b742410             mov esi, dword ptr [esp + 0x10]
// 008f671a  57                   push edi
// 008f671b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f671f  c644240800           mov byte ptr [esp + 8], 0
// 008f6724  8b442408             mov eax, dword ptr [esp + 8]
// 008f6728  50                   push eax
// 008f6729  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f672d  52                   push edx
// 008f672e  83c108               add ecx, 8
// 008f6731  51                   push ecx
// 008f6732  50                   push eax
// 008f6733  56                   push esi
// 008f6734  57                   push edi
// 008f6735  e8e6c7ffff           call 0x8f2f20
// 008f673a  8bc6                 mov eax, esi
// 008f673c  6bc02c               imul eax, eax, 0x2c
// 008f673f  83c418               add esp, 0x18
// 008f6742  03c7                 add eax, edi
// 008f6744  5f                   pop edi
// 008f6745  5e                   pop esi
// 008f6746  59                   pop ecx
// 008f6747  c20c00               ret 0xc
// library ogre-1.7.0/OgreSkeleton.cpp (function ?_Ufill@?$vector@UDeltaTransform@Ogre@@V?$allocator@UDeltaTransform@Ogre@@@std@@@std@@IAEPAUDeltaTransform@Ogre@@PAU34@IABU34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSkeleton.cpp
