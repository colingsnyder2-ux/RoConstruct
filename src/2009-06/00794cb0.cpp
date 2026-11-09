// from server: 100% by auto
// roc 2009-06 00794cb0  unit: CXTPRibbonTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00794cb0
//
// 00794cb0  56                   push esi
// 00794cb1  8bf1                 mov esi, ecx
// 00794cb3  e838780700           call 0x80c4f0
// 00794cb8  c70638039000         mov dword ptr [esi], 0x900338
// 00794cbe  8bc6                 mov eax, esi
// 00794cc0  5e                   pop esi
// 00794cc1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
