// from server: 100% by auto
// roc 2007-08 00651f40  unit: CXTPReportViewPrintOptions  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00651f40
//
// 00651f40  56                   push esi
// 00651f41  8bf1                 mov esi, ecx
// 00651f43  e8c8fd0200           call 0x681d10
// 00651f48  c706d4787c00         mov dword ptr [esi], 0x7c78d4
// 00651f4e  8bc6                 mov eax, esi
// 00651f50  5e                   pop esi
// 00651f51  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
