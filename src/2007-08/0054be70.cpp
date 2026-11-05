// from server: 100% by colin
// roc 2007-08 0054be70  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054be70
//
// 0054be70  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054be74  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054be78  50                   push eax
// 0054be79  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054be7d  52                   push edx
// 0054be7e  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054be82  50                   push eax
// 0054be83  8b442424             mov eax, dword ptr [esp + 0x24]
// 0054be87  52                   push edx
// 0054be88  50                   push eax
// 0054be89  51                   push ecx
// 0054be8a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054be8e  51                   push ecx
// 0054be8f  e8fcfeffff           call 0x54bd90
// copied from an identical function in another client (function ??$seek@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@iostreams@boost@@@?$concept_adapter@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@@detail@iostreams@boost@@QAE?AV?$fpos@H@std@@_JHHPAV?$linked_streambuf@DU?$char_traits@D@std@@@123@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp