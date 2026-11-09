// from server: 100% by auto
// roc 2011-06 00900c20  unit: CXTColorSelectorCtrlThemeOfficeXP  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00900c20
//
// 00900c20  56                   push esi
// 00900c21  8bf1                 mov esi, ecx
// 00900c23  e868ffffff           call 0x900b90
// 00900c28  c70604e1ad00         mov dword ptr [esi], 0xade104
// 00900c2e  8bc6                 mov eax, esi
// 00900c30  5e                   pop esi
// 00900c31  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
