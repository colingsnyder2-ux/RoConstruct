// from server: 100% by auto
// roc 2010-06 0082c570  unit: CXTPRibbonTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082c570
//
// 0082c570  56                   push esi
// 0082c571  8bf1                 mov esi, ecx
// 0082c573  e888f80600           call 0x89be00
// 0082c578  c7065c58a600         mov dword ptr [esi], 0xa6585c
// 0082c57e  8bc6                 mov eax, esi
// 0082c580  5e                   pop esi
// 0082c581  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
