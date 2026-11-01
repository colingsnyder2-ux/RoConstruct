// from server: 100% by colin
// roc 2007-03 0054ab10  unit: seg_00540000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054ab10
//
// 0054ab10  51                   push ecx
// 0054ab11  8b0424               mov eax, dword ptr [esp]
// 0054ab14  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0054ab18  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0054ab1c  50                   push eax
// 0054ab1d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054ab21  51                   push ecx
// 0054ab22  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054ab26  52                   push edx
// 0054ab27  8b542418             mov edx, dword ptr [esp + 0x18]
// 0054ab2b  50                   push eax
// 0054ab2c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0054ab30  51                   push ecx
// 0054ab31  52                   push edx
// 0054ab32  50                   push eax
// 0054ab33  e8b8ffffff           call 0x54aaf0
// copied from an identical function in another client (function ??$seek@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@23@@?$device_wrapper_impl@Uany_tag@iostreams@boost@@@detail@iostreams@boost@@SA?AV?$fpos@H@std@@AAV?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@PAV?$linked_streambuf@DU?$char_traits@D@std@@@123@_JHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp