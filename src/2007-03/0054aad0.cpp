// from server: 100% by colin
// roc 2007-03 0054aad0  unit: seg_00540000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054aad0
//
// 0054aad0  8d4424d8             lea eax, [esp - 0x28]
// 0054aad4  83ec28               sub esp, 0x28
// 0054aad7  50                   push eax
// 0054aad8  e813feffff           call 0x54a8f0
// 0054aadd  83c404               add esp, 4
// 0054aae0  68dc818500           push 0x8581dc
// 0054aae5  8d4c2404             lea ecx, [esp + 4]
// 0054aae9  51                   push ecx
// 0054aaea  e83f450d00           call 0x61f02e
// copied from an identical function in another client (function ??$read@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@V?$linked_streambuf@DU?$char_traits@D@std@@@detail@23@@?$device_wrapper_impl@Uoutput@iostreams@boost@@@detail@iostreams@boost@@SAHAAV?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@PAV?$linked_streambuf@DU?$char_traits@D@std@@@123@PADH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp