// from server: 100% by colin
// roc 2007-08 0054f490  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054f490
//
// 0054f490  8d4424d8             lea eax, [esp - 0x28]
// 0054f494  83ec28               sub esp, 0x28
// 0054f497  50                   push eax
// 0054f498  e8f3bdffff           call 0x54b290
// 0054f49d  83c404               add esp, 4
// 0054f4a0  68c49a8500           push 0x859ac4
// 0054f4a5  8d4c2404             lea ecx, [esp + 4]
// 0054f4a9  51                   push ecx
// 0054f4aa  e8ef160e00           call 0x630b9e
// copied from an identical function in another client (function ??$read@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@23@@?$device_wrapper_impl@Uoutput@iostreams@boost@@@detail@iostreams@boost@@SAHAAV?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@PAV?$linked_streambuf@DU?$char_traits@D@std@@@123@PADH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp