// from server: 100% by auto
// roc 2007-08 00696ec0  unit: CXTPToolTipContext::CRichEditToolTip  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00696ec0
//
// 00696ec0  8b442404             mov eax, dword ptr [esp + 4]
// 00696ec4  50                   push eax
// 00696ec5  e88687feff           call 0x67f650
// 00696eca  83c404               add esp, 4
// 00696ecd  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
