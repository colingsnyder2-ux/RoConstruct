// from server: 100% by auto
// roc 2012-06 00a78e30  unit: CXTColorSelectorCtrlThemeOfficeXP  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a78e30
//
// 00a78e30  56                   push esi
// 00a78e31  8bf1                 mov esi, ecx
// 00a78e33  e868ffffff           call 0xa78da0
// 00a78e38  c706c497c200         mov dword ptr [esi], 0xc297c4
// 00a78e3e  8bc6                 mov eax, esi
// 00a78e40  5e                   pop esi
// 00a78e41  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
