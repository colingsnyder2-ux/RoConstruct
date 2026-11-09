// from server: 100% by auto
// roc 2012-06 0062a740  unit: G3D::MemoryManager  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062a740
//
// 0062a740  8b442404             mov eax, dword ptr [esp + 4]
// 0062a744  50                   push eax
// 0062a745  e8c6d1f7ff           call 0x5a7910
// 0062a74a  83c404               add esp, 4
// 0062a74d  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
