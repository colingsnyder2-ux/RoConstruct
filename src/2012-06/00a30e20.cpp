// from server: 100% by auto
// roc 2012-06 00a30e20  unit: CXTPReportHyperlinks  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a30e20
//
// 00a30e20  56                   push esi
// 00a30e21  8bf1                 mov esi, ecx
// 00a30e23  e8f8fcffff           call 0xa30b20
// 00a30e28  c7067c05c200         mov dword ptr [esi], 0xc2057c
// 00a30e2e  8bc6                 mov eax, esi
// 00a30e30  5e                   pop esi
// 00a30e31  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
