// from server: 100% by colin
// roc 2007-03 0054c8e0  unit: seg_00540000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054c8e0
//
// 0054c8e0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054c8e4  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054c8e8  50                   push eax
// 0054c8e9  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054c8ed  52                   push edx
// 0054c8ee  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054c8f2  50                   push eax
// 0054c8f3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0054c8f7  52                   push edx
// 0054c8f8  50                   push eax
// 0054c8f9  51                   push ecx
// 0054c8fa  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054c8fe  51                   push ecx
// 0054c8ff  e84cffffff           call 0x54c850
// copied from an identical function in another client (function ??$seek@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@iostreams@boost@@@?$concept_adapter@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@@detail@iostreams@boost@@QAE?AV?$fpos@H@std@@_JHHPAV?$linked_streambuf@DU?$char_traits@D@std@@@123@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp