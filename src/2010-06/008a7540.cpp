// from server: 100% by auto
// roc 2010-06 008a7540  unit: CXTColorSelectorCtrlThemeOfficeXP  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7540
//
// 008a7540  56                   push esi
// 008a7541  8bf1                 mov esi, ecx
// 008a7543  e868ffffff           call 0x8a74b0
// 008a7548  c706ac3ca700         mov dword ptr [esi], 0xa73cac
// 008a754e  8bc6                 mov eax, esi
// 008a7550  5e                   pop esi
// 008a7551  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
