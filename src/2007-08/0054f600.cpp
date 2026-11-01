// from server: 100% by colin
// roc 2007-08 0054f600  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054f600
//
// 0054f600  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054f604  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054f608  50                   push eax
// 0054f609  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054f60d  52                   push edx
// 0054f60e  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054f612  50                   push eax
// 0054f613  8b442424             mov eax, dword ptr [esp + 0x24]
// 0054f617  52                   push edx
// 0054f618  50                   push eax
// 0054f619  51                   push ecx
// 0054f61a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054f61e  51                   push ecx
// 0054f61f  e8dcfeffff           call 0x54f500
// copied from an identical function in another client (function ??$seek@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@iostreams@boost@@@?$concept_adapter@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@@detail@iostreams@boost@@QAE?AV?$fpos@H@std@@_JHHPAV?$linked_streambuf@DU?$char_traits@D@std@@@123@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp