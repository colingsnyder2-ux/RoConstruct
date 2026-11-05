// from server: 100% by colin
// roc 2007-08 0054fc50  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054fc50
//
// 0054fc50  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054fc54  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0054fc58  50                   push eax
// 0054fc59  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0054fc5d  52                   push edx
// 0054fc5e  99                   cdq 
// 0054fc5f  52                   push edx
// 0054fc60  50                   push eax
// 0054fc61  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054fc65  50                   push eax
// 0054fc66  e825ebffff           call 0x54e790
// copied from an identical function in another client (function ?seekoff@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAE?AV?$fpos@H@std@@JHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp