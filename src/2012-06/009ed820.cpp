// from server: 100% by auto
// roc 2012-06 009ed820  unit: CXTPToolTipContextToolTip  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ed820
//
// 009ed820  8b442404             mov eax, dword ptr [esp + 4]
// 009ed824  50                   push eax
// 009ed825  e8e66efeff           call 0x9d4710
// 009ed82a  83c404               add esp, 4
// 009ed82d  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
