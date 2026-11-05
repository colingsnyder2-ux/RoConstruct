// from server: 100% by auto
// roc 2008-06 006c7db0  unit: PAVCXTPReportInplaceButton::?$CArray  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006c7db0
//
// 006c7db0  56                   push esi
// 006c7db1  8bf1                 mov esi, ecx
// 006c7db3  e878ffffff           call 0x6c7d30
// 006c7db8  c706c4348500         mov dword ptr [esi], 0x8534c4
// 006c7dbe  8bc6                 mov eax, esi
// 006c7dc0  5e                   pop esi
// 006c7dc1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
