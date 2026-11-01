// from server: 100% by auto
// roc 2010-06 008f67d0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f67d0
//
// 008f67d0  51                   push ecx
// 008f67d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f67d5  56                   push esi
// 008f67d6  8b742410             mov esi, dword ptr [esp + 0x10]
// 008f67da  57                   push edi
// 008f67db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f67df  c644240800           mov byte ptr [esp + 8], 0
// 008f67e4  8b442408             mov eax, dword ptr [esp + 8]
// 008f67e8  50                   push eax
// 008f67e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f67ed  52                   push edx
// 008f67ee  83c108               add ecx, 8
// 008f67f1  51                   push ecx
// 008f67f2  50                   push eax
// 008f67f3  56                   push esi
// 008f67f4  57                   push edi
// 008f67f5  e846ddffff           call 0x8f4540
// 008f67fa  8bce                 mov ecx, esi
// 008f67fc  83c418               add esp, 0x18
// 008f67ff  c1e104               shl ecx, 4
// 008f6802  2bce                 sub ecx, esi
// 008f6804  8d048f               lea eax, [edi + ecx*4]
// 008f6807  5f                   pop edi
// 008f6808  5e                   pop esi
// 008f6809  59                   pop ecx
// 008f680a  c20c00               ret 0xc
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Ufill@?$vector@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@std@@IAEPAVParameterDef@Ogre@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
