// from server: 100% by auto
// roc 2009-12 004a2ab0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2ab0
//
// 004a2ab0  51                   push ecx
// 004a2ab1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2ab5  56                   push esi
// 004a2ab6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a2aba  57                   push edi
// 004a2abb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a2abf  c644240800           mov byte ptr [esp + 8], 0
// 004a2ac4  8b442408             mov eax, dword ptr [esp + 8]
// 004a2ac8  50                   push eax
// 004a2ac9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2acd  52                   push edx
// 004a2ace  83c108               add ecx, 8
// 004a2ad1  51                   push ecx
// 004a2ad2  50                   push eax
// 004a2ad3  56                   push esi
// 004a2ad4  57                   push edi
// 004a2ad5  e826c7ffff           call 0x49f200
// 004a2ada  8bc6                 mov eax, esi
// 004a2adc  6bc02c               imul eax, eax, 0x2c
// 004a2adf  83c418               add esp, 0x18
// 004a2ae2  03c7                 add eax, edi
// 004a2ae4  5f                   pop edi
// 004a2ae5  5e                   pop esi
// 004a2ae6  59                   pop ecx
// 004a2ae7  c20c00               ret 0xc
// library ogre-1.7.0/OgreSkeleton.cpp (function ?_Ufill@?$vector@UDeltaTransform@Ogre@@V?$allocator@UDeltaTransform@Ogre@@@std@@@std@@IAEPAUDeltaTransform@Ogre@@PAU34@IABU34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSkeleton.cpp
