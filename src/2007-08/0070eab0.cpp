// from server: 100% by auto
// roc 2007-08 0070eab0  unit: CXTSplitterWndThemeFactory  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070eab0
//
// 0070eab0  56                   push esi
// 0070eab1  8bf1                 mov esi, ecx
// 0070eab3  e8982ef8ff           call 0x691950
// 0070eab8  c706fce27d00         mov dword ptr [esi], 0x7de2fc
// 0070eabe  8bc6                 mov eax, esi
// 0070eac0  5e                   pop esi
// 0070eac1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
