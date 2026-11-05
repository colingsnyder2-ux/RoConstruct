// from server: 100% by auto
// roc 2010-06 00884e30  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884e30
//
// 00884e30  56                   push esi
// 00884e31  8bf1                 mov esi, ecx
// 00884e33  e8c887faff           call 0x82d600
// 00884e38  c706b4eda600         mov dword ptr [esi], 0xa6edb4
// 00884e3e  8bc6                 mov eax, esi
// 00884e40  5e                   pop esi
// 00884e41  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
