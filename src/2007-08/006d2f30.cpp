// from server: 100% by auto
// roc 2007-08 006d2f30  unit: CXTPReportHyperlinks  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d2f30
//
// 006d2f30  56                   push esi
// 006d2f31  8bf1                 mov esi, ecx
// 006d2f33  e8f8fcffff           call 0x6d2c30
// 006d2f38  c706c4817d00         mov dword ptr [esi], 0x7d81c4
// 006d2f3e  8bc6                 mov eax, esi
// 006d2f40  5e                   pop esi
// 006d2f41  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
