// from server: 100% by colin
// roc 2007-08 0054bd90  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054bd90
//
// 0054bd90  51                   push ecx
// 0054bd91  8b0424               mov eax, dword ptr [esp]
// 0054bd94  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0054bd98  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0054bd9c  50                   push eax
// 0054bd9d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054bda1  51                   push ecx
// 0054bda2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054bda6  52                   push edx
// 0054bda7  8b542418             mov edx, dword ptr [esp + 0x18]
// 0054bdab  50                   push eax
// 0054bdac  8b442418             mov eax, dword ptr [esp + 0x18]
// 0054bdb0  51                   push ecx
// 0054bdb1  52                   push edx
// 0054bdb2  50                   push eax
// 0054bdb3  e8d8360000           call 0x54f490
// copied from an identical function in another client (function ??$seek@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@23@@?$device_wrapper_impl@Uany_tag@iostreams@boost@@@detail@iostreams@boost@@SA?AV?$fpos@H@std@@AAV?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@PAV?$linked_streambuf@DU?$char_traits@D@std@@@123@_JHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp