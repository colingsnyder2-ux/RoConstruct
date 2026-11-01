// from server: 100% by colin
// roc 2007-03 0054ad80  unit: seg_00540000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054ad80
//
// 0054ad80  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054ad84  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054ad88  50                   push eax
// 0054ad89  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054ad8d  52                   push edx
// 0054ad8e  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054ad92  50                   push eax
// 0054ad93  8b442424             mov eax, dword ptr [esp + 0x24]
// 0054ad97  52                   push edx
// 0054ad98  50                   push eax
// 0054ad99  51                   push ecx
// 0054ad9a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054ad9e  51                   push ecx
// 0054ad9f  e86cfdffff           call 0x54ab10
// copied from an identical function in another client (function ??$seek@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@iostreams@boost@@@?$concept_adapter@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@@detail@iostreams@boost@@QAE?AV?$fpos@H@std@@_JHHPAV?$linked_streambuf@DU?$char_traits@D@std@@@123@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp