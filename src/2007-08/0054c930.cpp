// from server: 100% by colin
// roc 2007-08 0054c930  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c930
//
// 0054c930  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054c934  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0054c938  50                   push eax
// 0054c939  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0054c93d  52                   push edx
// 0054c93e  99                   cdq 
// 0054c93f  52                   push edx
// 0054c940  50                   push eax
// 0054c941  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054c945  50                   push eax
// 0054c946  e815f9ffff           call 0x54c260
// copied from an identical function in another client (function ?seekoff@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAE?AV?$fpos@H@std@@JHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp