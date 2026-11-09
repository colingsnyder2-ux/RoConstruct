// from server: 100% by auto
// roc 2008-06 0074d1c0  unit: CXTPReportRecordItemPreview  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0074d1c0
//
// 0074d1c0  56                   push esi
// 0074d1c1  8bf1                 mov esi, ecx
// 0074d1c3  e808a0f7ff           call 0x6c71d0
// 0074d1c8  c706283e8600         mov dword ptr [esi], 0x863e28
// 0074d1ce  8bc6                 mov eax, esi
// 0074d1d0  5e                   pop esi
// 0074d1d1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
