// from server: 100% by auto
// roc 2009-12 004a2b70  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2b70
//
// 004a2b70  51                   push ecx
// 004a2b71  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2b75  56                   push esi
// 004a2b76  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a2b7a  57                   push edi
// 004a2b7b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a2b7f  c644240800           mov byte ptr [esp + 8], 0
// 004a2b84  8b442408             mov eax, dword ptr [esp + 8]
// 004a2b88  50                   push eax
// 004a2b89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2b8d  52                   push edx
// 004a2b8e  83c108               add ecx, 8
// 004a2b91  51                   push ecx
// 004a2b92  50                   push eax
// 004a2b93  56                   push esi
// 004a2b94  57                   push edi
// 004a2b95  e886dcffff           call 0x4a0820
// 004a2b9a  8bce                 mov ecx, esi
// 004a2b9c  83c418               add esp, 0x18
// 004a2b9f  c1e104               shl ecx, 4
// 004a2ba2  2bce                 sub ecx, esi
// 004a2ba4  8d048f               lea eax, [edi + ecx*4]
// 004a2ba7  5f                   pop edi
// 004a2ba8  5e                   pop esi
// 004a2ba9  59                   pop ecx
// 004a2baa  c20c00               ret 0xc
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Ufill@?$vector@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@std@@IAEPAVParameterDef@Ogre@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
