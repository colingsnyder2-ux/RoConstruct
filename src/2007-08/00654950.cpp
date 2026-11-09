// from server: 100% by auto
// roc 2007-08 00654950  unit: PAVCXTPReportInplaceButton::?$CArray  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00654950
//
// 00654950  56                   push esi
// 00654951  8bf1                 mov esi, ecx
// 00654953  e878ffffff           call 0x6548d0
// 00654958  c706b07f7c00         mov dword ptr [esi], 0x7c7fb0
// 0065495e  8bc6                 mov eax, esi
// 00654960  5e                   pop esi
// 00654961  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
