// from server: 100% by auto
// roc 2010-06 00514d90  unit: RakPeer  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00514d90
//
// 00514d90  8b442404             mov eax, dword ptr [esp + 4]
// 00514d94  50                   push eax
// 00514d95  e8f6f4ffff           call 0x514290
// 00514d9a  83c404               add esp, 4
// 00514d9d  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
