// from server: 100% by auto
// roc 2010-06 00855420  unit: CXTPReportRecordItemPreview  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00855420
//
// 00855420  56                   push esi
// 00855421  8bf1                 mov esi, ecx
// 00855423  e80893f7ff           call 0x7ce730
// 00855428  c706e096a600         mov dword ptr [esi], 0xa696e0
// 0085542e  8bc6                 mov eax, esi
// 00855430  5e                   pop esi
// 00855431  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
