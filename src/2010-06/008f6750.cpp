// from server: 100% by auto
// roc 2010-06 008f6750  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6750
//
// 008f6750  51                   push ecx
// 008f6751  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6755  56                   push esi
// 008f6756  8b742410             mov esi, dword ptr [esp + 0x10]
// 008f675a  57                   push edi
// 008f675b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f675f  c644240800           mov byte ptr [esp + 8], 0
// 008f6764  8b442408             mov eax, dword ptr [esp + 8]
// 008f6768  50                   push eax
// 008f6769  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f676d  52                   push edx
// 008f676e  83c108               add ecx, 8
// 008f6771  51                   push ecx
// 008f6772  50                   push eax
// 008f6773  56                   push esi
// 008f6774  57                   push edi
// 008f6775  e856cfffff           call 0x8f36d0
// 008f677a  83c418               add esp, 0x18
// 008f677d  8d0cf500000000       lea ecx, [esi*8]
// 008f6784  2bce                 sub ecx, esi
// 008f6786  8d04cf               lea eax, [edi + ecx*8]
// 008f6789  5f                   pop edi
// 008f678a  5e                   pop esi
// 008f678b  59                   pop ecx
// 008f678c  c20c00               ret 0xc
// library ogre-1.7.0/OgreMaterialSerializer.cpp (function ?_Ufill@?$vector@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@PAU32@IABU32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMaterialSerializer.cpp
