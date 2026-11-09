// from server: 100% by auto
// roc 2007-08 006d0fa0  unit: CXTPReportPaintManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d0fa0
//
// 006d0fa0  56                   push esi
// 006d0fa1  8bf1                 mov esi, ecx
// 006d0fa3  e8682ef8ff           call 0x653e10
// 006d0fa8  c706d07b7d00         mov dword ptr [esi], 0x7d7bd0
// 006d0fae  8bc6                 mov eax, esi
// 006d0fb0  5e                   pop esi
// 006d0fb1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
