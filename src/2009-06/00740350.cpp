// from server: 100% by auto
// roc 2009-06 00740350  unit: PAVCXTPReportInplaceButton::?$CArray  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00740350
//
// 00740350  56                   push esi
// 00740351  8bf1                 mov esi, ecx
// 00740353  e878ffffff           call 0x7402d0
// 00740358  c70614458f00         mov dword ptr [esi], 0x8f4514
// 0074035e  8bc6                 mov eax, esi
// 00740360  5e                   pop esi
// 00740361  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
