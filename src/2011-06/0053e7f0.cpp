// from server: 100% by auto
// roc 2011-06 0053e7f0  unit: G3D::MemoryManager  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053e7f0
//
// 0053e7f0  8b442404             mov eax, dword ptr [esp + 4]
// 0053e7f4  50                   push eax
// 0053e7f5  e836040000           call 0x53ec30
// 0053e7fa  83c404               add esp, 4
// 0053e7fd  c20400               ret 4
// library boost-1.36.0/libs\regex\src\wide_posix_api.cpp (function ?translate_nocase@?$c_regex_traits@_W@boost@@QBE_W_W@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/wide_posix_api.cpp
