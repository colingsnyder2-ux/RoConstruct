// from server: 100% by auto
// roc 2009-12 004ac720  unit: Ogre::RbxSceneUpdater  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ac720
//
// 004ac720  51                   push ecx
// 004ac721  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ac725  56                   push esi
// 004ac726  8b742410             mov esi, dword ptr [esp + 0x10]
// 004ac72a  57                   push edi
// 004ac72b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ac72f  c644240800           mov byte ptr [esp + 8], 0
// 004ac734  8b442408             mov eax, dword ptr [esp + 8]
// 004ac738  50                   push eax
// 004ac739  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ac73d  52                   push edx
// 004ac73e  83c108               add ecx, 8
// 004ac741  51                   push ecx
// 004ac742  50                   push eax
// 004ac743  56                   push esi
// 004ac744  57                   push edi
// 004ac745  e8d6fdffff           call 0x4ac520
// 004ac74a  8d04b6               lea eax, [esi + esi*4]
// 004ac74d  83c418               add esp, 0x18
// 004ac750  c1e004               shl eax, 4
// 004ac753  03c7                 add eax, edi
// 004ac755  5f                   pop edi
// 004ac756  5e                   pop esi
// 004ac757  59                   pop ecx
// 004ac758  c20c00               ret 0xc
// library boost-1.44.0/libs\regex\src\instances.cpp (function ?_Ufill@?$vector@U?$recursion_info@V?$match_results@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@U?$sub_match@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@boost@@@2@@boost@@@re_detail@boost@@V?$allocator@U?$recursion_info@V?$match_results@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@U?$sub_match@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@boost@@@2@@boost@@@re_detail@boost@@@std@@@std@@IAEPAU?$recursion_info@V?$match_results@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@U?$sub_match@V?$_String_const_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@boost@@@2@@boost@@@re_detail@boost@@PAU345@IABU345@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.44.0 libs/regex/src/instances.cpp
