// from server: 100% by auto
// roc 2010-06 007cf310  unit: PAVCXTPReportInplaceButton::?$CArray  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cf310
//
// 007cf310  56                   push esi
// 007cf311  8bf1                 mov esi, ecx
// 007cf313  e878ffffff           call 0x7cf290
// 007cf318  c706c08ca500         mov dword ptr [esi], 0xa58cc0
// 007cf31e  8bc6                 mov eax, esi
// 007cf320  5e                   pop esi
// 007cf321  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
