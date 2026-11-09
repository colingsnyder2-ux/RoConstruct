// from server: 100% by auto
// roc 2012-06 009b7d70  unit: PAVCXTPReportInplaceButton::?$CArray  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b7d70
//
// 009b7d70  56                   push esi
// 009b7d71  8bf1                 mov esi, ecx
// 009b7d73  e878ffffff           call 0x9b7cf0
// 009b7d78  c7060c0ec100         mov dword ptr [esi], 0xc10e0c
// 009b7d7e  8bc6                 mov eax, esi
// 009b7d80  5e                   pop esi
// 009b7d81  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
