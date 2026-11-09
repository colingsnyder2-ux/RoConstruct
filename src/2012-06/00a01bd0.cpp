// from server: 100% by auto
// roc 2012-06 00a01bd0  unit: CXTPRibbonTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a01bd0
//
// 00a01bd0  56                   push esi
// 00a01bd1  8bf1                 mov esi, ecx
// 00a01bd3  e8e8b00600           call 0xa6ccc0
// 00a01bd8  c70634b9c100         mov dword ptr [esi], 0xc1b934
// 00a01bde  8bc6                 mov eax, esi
// 00a01be0  5e                   pop esi
// 00a01be1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
