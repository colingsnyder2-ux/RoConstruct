// from server: 100% by auto
// roc 2007-08 006fff10  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fff10
//
// 006fff10  56                   push esi
// 006fff11  8bf1                 mov esi, ecx
// 006fff13  e8f8e1faff           call 0x6ae110
// 006fff18  c706d4d17d00         mov dword ptr [esi], 0x7dd1d4
// 006fff1e  8bc6                 mov eax, esi
// 006fff20  5e                   pop esi
// 006fff21  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
