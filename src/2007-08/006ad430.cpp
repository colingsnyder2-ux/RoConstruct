// from server: 100% by auto
// roc 2007-08 006ad430  unit: CXTPRibbonTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ad430
//
// 006ad430  56                   push esi
// 006ad431  8bf1                 mov esi, ecx
// 006ad433  e848dd0600           call 0x71b180
// 006ad438  c70688567d00         mov dword ptr [esi], 0x7d5688
// 006ad43e  8bc6                 mov eax, esi
// 006ad440  5e                   pop esi
// 006ad441  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
