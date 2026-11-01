// from server: 100% by colin
// roc 2007-03 0054b610  unit: seg_00540000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054b610
//
// 0054b610  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 0054b613  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0054b616  8902                 mov dword ptr [edx], eax
// 0054b618  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0054b61b  8902                 mov dword ptr [edx], eax
// 0054b61d  8bd0                 mov edx, eax
// 0054b61f  2bd0                 sub edx, eax
// 0054b621  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0054b624  8910                 mov dword ptr [eax], edx
// 0054b626  c3                   ret 
// copied from an identical function in another client (function ?init_get_area@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@EAEXXZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp