// from server: 100% by auto
// roc 2010-06 00817a90  unit: CXTPToolTipContextToolTip  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00817a90
//
// 00817a90  8b442404             mov eax, dword ptr [esp + 4]
// 00817a94  50                   push eax
// 00817a95  e8d66dfeff           call 0x7fe870
// 00817a9a  83c404               add esp, 4
// 00817a9d  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
