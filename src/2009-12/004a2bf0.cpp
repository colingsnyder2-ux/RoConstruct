// from server: 100% by auto
// roc 2009-12 004a2bf0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2bf0
//
// 004a2bf0  51                   push ecx
// 004a2bf1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2bf5  56                   push esi
// 004a2bf6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a2bfa  57                   push edi
// 004a2bfb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a2bff  c644240800           mov byte ptr [esp + 8], 0
// 004a2c04  8b442408             mov eax, dword ptr [esp + 8]
// 004a2c08  50                   push eax
// 004a2c09  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2c0d  52                   push edx
// 004a2c0e  83c108               add ecx, 8
// 004a2c11  51                   push ecx
// 004a2c12  50                   push eax
// 004a2c13  56                   push esi
// 004a2c14  57                   push edi
// 004a2c15  e886ebffff           call 0x4a17a0
// 004a2c1a  8bce                 mov ecx, esi
// 004a2c1c  83c418               add esp, 0x18
// 004a2c1f  c1e104               shl ecx, 4
// 004a2c22  03ce                 add ecx, esi
// 004a2c24  8d048f               lea eax, [edi + ecx*4]
// 004a2c27  5f                   pop edi
// 004a2c28  5e                   pop esi
// 004a2c29  59                   pop ecx
// 004a2c2a  c20c00               ret 0xc
// library boost-1.44.0/libs\regex\src\instances.cpp (function ?_Ufill@?$vector@U?$recursion_info@V?$match_results@PBDV?$allocator@U?$sub_match@PBD@boost@@@std@@@boost@@@re_detail@boost@@V?$allocator@U?$recursion_info@V?$match_results@PBDV?$allocator@U?$sub_match@PBD@boost@@@std@@@boost@@@re_detail@boost@@@std@@@std@@IAEPAU?$recursion_info@V?$match_results@PBDV?$allocator@U?$sub_match@PBD@boost@@@std@@@boost@@@re_detail@boost@@PAU345@IABU345@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.44.0 libs/regex/src/instances.cpp
