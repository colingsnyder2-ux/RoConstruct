// from server: 100% by colin
// roc 2007-08 0054b440  unit: UString_sink::?$stream_buffer  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054b440
//
// 0054b440  8d4424d8             lea eax, [esp - 0x28]
// 0054b444  83ec28               sub esp, 0x28
// 0054b447  50                   push eax
// 0054b448  e8c3fdffff           call 0x54b210
// 0054b44d  83c404               add esp, 4
// 0054b450  68c49a8500           push 0x859ac4
// 0054b455  8d4c2404             lea ecx, [esp + 4]
// 0054b459  51                   push ecx
// 0054b45a  e83f570e00           call 0x630b9e
// copied from an identical function in another client (function ??$read@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@23@@?$device_wrapper_impl@Uoutput@iostreams@boost@@@detail@iostreams@boost@@SAHAAV?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@PAV?$linked_streambuf@DU?$char_traits@D@std@@@123@PADH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp