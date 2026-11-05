// from server: 100% by auto
// roc 2011-06 008f13c0  unit: CXTCaptionTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f13c0
//
// 008f13c0  56                   push esi
// 008f13c1  8bf1                 mov esi, ecx
// 008f13c3  e868ffffff           call 0x8f1330
// 008f13c8  c7062ca2ad00         mov dword ptr [esi], 0xada22c
// 008f13ce  8bc6                 mov eax, esi
// 008f13d0  5e                   pop esi
// 008f13d1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
