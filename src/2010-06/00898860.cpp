// from server: 100% by auto
// roc 2010-06 00898860  unit: CXTCaptionTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898860
//
// 00898860  56                   push esi
// 00898861  8bf1                 mov esi, ecx
// 00898863  e868ffffff           call 0x8987d0
// 00898868  c7060407a700         mov dword ptr [esi], 0xa70704
// 0089886e  8bc6                 mov eax, esi
// 00898870  5e                   pop esi
// 00898871  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
