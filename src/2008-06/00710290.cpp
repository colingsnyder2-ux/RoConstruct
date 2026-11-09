// from server: 100% by auto
// roc 2008-06 00710290  unit: CXTPStatusBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00710290
//
// 00710290  8b442404             mov eax, dword ptr [esp + 4]
// 00710294  50                   push eax
// 00710295  e8066efeff           call 0x6f70a0
// 0071029a  83c404               add esp, 4
// 0071029d  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
