// from server: 100% by auto
// roc 2011-06 008752c0  unit: CXTPToolTipContextToolTip  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008752c0
//
// 008752c0  8b442404             mov eax, dword ptr [esp + 4]
// 008752c4  50                   push eax
// 008752c5  e82670feff           call 0x85c2f0
// 008752ca  83c404               add esp, 4
// 008752cd  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
