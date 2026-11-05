// from server: 100% by auto
// roc 2009-12 004b52d0  unit: Ogre::RbxMaterialAdapter  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b52d0
//
// 004b52d0  51                   push ecx
// 004b52d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b52d5  56                   push esi
// 004b52d6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004b52da  57                   push edi
// 004b52db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004b52df  c644240800           mov byte ptr [esp + 8], 0
// 004b52e4  8b442408             mov eax, dword ptr [esp + 8]
// 004b52e8  50                   push eax
// 004b52e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b52ed  52                   push edx
// 004b52ee  83c108               add ecx, 8
// 004b52f1  51                   push ecx
// 004b52f2  50                   push eax
// 004b52f3  56                   push esi
// 004b52f4  57                   push edi
// 004b52f5  e8e6f5ffff           call 0x4b48e0
// 004b52fa  8bce                 mov ecx, esi
// 004b52fc  83c418               add esp, 0x18
// 004b52ff  c1e104               shl ecx, 4
// 004b5302  03ce                 add ecx, esi
// 004b5304  8d048f               lea eax, [edi + ecx*4]
// 004b5307  5f                   pop edi
// 004b5308  5e                   pop esi
// 004b5309  59                   pop ecx
// 004b530a  c20c00               ret 0xc
// library boost-1.44.0/libs\regex\src\instances.cpp (function ?_Ufill@?$vector@U?$recursion_info@V?$match_results@PBDV?$allocator@U?$sub_match@PBD@boost@@@std@@@boost@@@re_detail@boost@@V?$allocator@U?$recursion_info@V?$match_results@PBDV?$allocator@U?$sub_match@PBD@boost@@@std@@@boost@@@re_detail@boost@@@std@@@std@@IAEPAU?$recursion_info@V?$match_results@PBDV?$allocator@U?$sub_match@PBD@boost@@@std@@@boost@@@re_detail@boost@@PAU345@IABU345@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.44.0 libs/regex/src/instances.cpp
