// from server: 100% by auto
// roc 2009-06 00788ab0  unit: CXTPToolTipContextToolTip  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00788ab0
//
// 00788ab0  8b442404             mov eax, dword ptr [esp + 4]
// 00788ab4  50                   push eax
// 00788ab5  e8866ffeff           call 0x76fa40
// 00788aba  83c404               add esp, 4
// 00788abd  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
