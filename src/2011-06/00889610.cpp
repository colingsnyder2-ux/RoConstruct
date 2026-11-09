// from server: 100% by auto
// roc 2011-06 00889610  unit: CXTPRibbonTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00889610
//
// 00889610  56                   push esi
// 00889611  8bf1                 mov esi, ecx
// 00889613  e848b30600           call 0x8f4960
// 00889618  c7067c02ad00         mov dword ptr [esi], 0xad027c
// 0088961e  8bc6                 mov eax, esi
// 00889620  5e                   pop esi
// 00889621  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
