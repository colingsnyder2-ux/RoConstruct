// from server: 100% by auto
// roc 2012-06 00a2d8c0  unit: CXTPReportRecordItemPreview  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2d8c0
//
// 00a2d8c0  56                   push esi
// 00a2d8c1  8bf1                 mov esi, ecx
// 00a2d8c3  e8c898f8ff           call 0x9b7190
// 00a2d8c8  c70698fbc100         mov dword ptr [esi], 0xc1fb98
// 00a2d8ce  8bc6                 mov eax, esi
// 00a2d8d0  5e                   pop esi
// 00a2d8d1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
