// roc 2012-06 0085c460  unit: UString_sink::?$stream_buffer  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085c460
//
// 0085c460  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 0085c463  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0085c466  8902                 mov dword ptr [edx], eax
// 0085c468  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0085c46b  8902                 mov dword ptr [edx], eax
// 0085c46d  8bd0                 mov edx, eax
// 0085c46f  2bd0                 sub edx, eax
// 0085c471  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0085c474  8910                 mov dword ptr [eax], edx
// 0085c476  c3                   ret 
// copied from an identical function in another client (function ?init_get_area@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@EAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp