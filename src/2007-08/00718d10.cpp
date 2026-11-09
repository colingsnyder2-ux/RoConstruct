// from server: 100% by auto
// roc 2007-08 00718d10  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00718d10
//
// 00718d10  56                   push esi
// 00718d11  8bf1                 mov esi, ecx
// 00718d13  e87831f6ff           call 0x67be90
// 00718d18  c706acf87d00         mov dword ptr [esi], 0x7df8ac
// 00718d1e  8bc6                 mov eax, esi
// 00718d20  5e                   pop esi
// 00718d21  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
