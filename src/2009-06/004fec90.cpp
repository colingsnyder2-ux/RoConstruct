// from server: 100% by auto
// roc 2009-06 004fec90  unit: RakPeer  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fec90
//
// 004fec90  8b442404             mov eax, dword ptr [esp + 4]
// 004fec94  50                   push eax
// 004fec95  e8f6f4ffff           call 0x4fe190
// 004fec9a  83c404               add esp, 4
// 004fec9d  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
