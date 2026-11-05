// from server: 100% by auto
// roc 2012-06 00a69730  unit: CXTCaptionTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a69730
//
// 00a69730  56                   push esi
// 00a69731  8bf1                 mov esi, ecx
// 00a69733  e868ffffff           call 0xa696a0
// 00a69738  c706c458c200         mov dword ptr [esi], 0xc258c4
// 00a6973e  8bc6                 mov eax, esi
// 00a69740  5e                   pop esi
// 00a69741  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
