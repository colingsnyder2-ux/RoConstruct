// from server: 100% by auto
// roc 2010-06 00857610  unit: CXTPReportHyperlinks  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857610
//
// 00857610  56                   push esi
// 00857611  8bf1                 mov esi, ecx
// 00857613  e8f8fcffff           call 0x857310
// 00857618  c706249da600         mov dword ptr [esi], 0xa69d24
// 0085761e  8bc6                 mov eax, esi
// 00857620  5e                   pop esi
// 00857621  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
