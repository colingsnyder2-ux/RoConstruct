// from server: 100% by auto
// roc 2011-06 0083f8c0  unit: PAVCXTPReportInplaceButton::?$CArray  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0083f8c0
//
// 0083f8c0  56                   push esi
// 0083f8c1  8bf1                 mov esi, ecx
// 0083f8c3  e878ffffff           call 0x83f840
// 0083f8c8  c7062457ac00         mov dword ptr [esi], 0xac5724
// 0083f8ce  8bc6                 mov eax, esi
// 0083f8d0  5e                   pop esi
// 0083f8d1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
