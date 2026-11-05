// from server: 100% by colin
// roc 2007-08 0054f9d0  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054f9d0
//
// 0054f9d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054f9d4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0054f9d8  50                   push eax
// 0054f9d9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0054f9dd  52                   push edx
// 0054f9de  99                   cdq 
// 0054f9df  52                   push edx
// 0054f9e0  50                   push eax
// 0054f9e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054f9e5  50                   push eax
// 0054f9e6  e8b5feffff           call 0x54f8a0
// copied from an identical function in another client (function ?seekoff@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAE?AV?$fpos@H@std@@JHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp