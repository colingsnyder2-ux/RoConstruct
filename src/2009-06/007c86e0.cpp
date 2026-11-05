// from server: 100% by auto
// roc 2009-06 007c86e0  unit: CXTPReportHyperlinks  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c86e0
//
// 007c86e0  56                   push esi
// 007c86e1  8bf1                 mov esi, ecx
// 007c86e3  e8f8fcffff           call 0x7c83e0
// 007c86e8  c706c4559000         mov dword ptr [esi], 0x9055c4
// 007c86ee  8bc6                 mov eax, esi
// 007c86f0  5e                   pop esi
// 007c86f1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
