// from server: 100% by auto
// roc 2011-06 008b5420  unit: CXTPReportTip  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b5420
//
// 008b5420  56                   push esi
// 008b5421  8bf1                 mov esi, ecx
// 008b5423  e89898f8ff           call 0x83ecc0
// 008b5428  c7060845ad00         mov dword ptr [esi], 0xad4508
// 008b542e  8bc6                 mov eax, esi
// 008b5430  5e                   pop esi
// 008b5431  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
