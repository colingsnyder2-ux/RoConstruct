// from server: 100% by auto
// roc 2008-06 0074f3e0  unit: CXTPReportHyperlinks  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0074f3e0
//
// 0074f3e0  56                   push esi
// 0074f3e1  8bf1                 mov esi, ecx
// 0074f3e3  e8f8fcffff           call 0x74f0e0
// 0074f3e8  c7066c448600         mov dword ptr [esi], 0x86446c
// 0074f3ee  8bc6                 mov eax, esi
// 0074f3f0  5e                   pop esi
// 0074f3f1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
