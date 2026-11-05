// from server: 100% by auto
// roc 2009-06 007c6490  unit: CXTPReportPaintManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c6490
//
// 007c6490  56                   push esi
// 007c6491  8bf1                 mov esi, ecx
// 007c6493  e8b892f7ff           call 0x73f750
// 007c6498  c706804f9000         mov dword ptr [esi], 0x904f80
// 007c649e  8bc6                 mov eax, esi
// 007c64a0  5e                   pop esi
// 007c64a1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
