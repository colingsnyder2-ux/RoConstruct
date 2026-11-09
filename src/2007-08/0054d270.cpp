// from server: 100% by colin
// roc 2007-08 0054d270  unit: UString_sink::?$stream_buffer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054d270
//
// 0054d270  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054d274  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0054d278  50                   push eax
// 0054d279  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0054d27d  52                   push edx
// 0054d27e  99                   cdq 
// 0054d27f  52                   push edx
// 0054d280  50                   push eax
// 0054d281  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054d285  50                   push eax
// 0054d286  e825f2ffff           call 0x54c4b0
// copied from an identical function in another client (function ?seekoff@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAE?AV?$fpos@H@std@@JHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp