// from server: 100% by auto
// roc 2011-06 008b8930  unit: CXTPReportHyperlinks  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b8930
//
// 008b8930  56                   push esi
// 008b8931  8bf1                 mov esi, ecx
// 008b8933  e8f8fcffff           call 0x8b8630
// 008b8938  c706ec4ead00         mov dword ptr [esi], 0xad4eec
// 008b893e  8bc6                 mov eax, esi
// 008b8940  5e                   pop esi
// 008b8941  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
