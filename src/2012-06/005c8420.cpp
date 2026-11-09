// roc 2012-06 005c8420  unit: RBX::AdornRbxGfx  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c8420
//
// 005c8420  8b442408             mov eax, dword ptr [esp + 8]
// 005c8424  8b542404             mov edx, dword ptr [esp + 4]
// 005c8428  50                   push eax
// 005c8429  52                   push edx
// 005c842a  e891ffffff           call 0x5c83c0
// 005c842f  c20c00               ret 0xc
// copied from an identical function in another client (function ??$write@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@iostreams@boost@@@?$concept_adapter@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@@detail@iostreams@boost@@QAEHPBDHPAV?$linked_streambuf@DU?$char_traits@D@std@@@123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp