// from server: 100% by auto
// roc 2011-06 008d5d50  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d5d50
//
// 008d5d50  56                   push esi
// 008d5d51  8bf1                 mov esi, ecx
// 008d5d53  e83849fbff           call 0x88a690
// 008d5d58  c7060c7dad00         mov dword ptr [esi], 0xad7d0c
// 008d5d5e  8bc6                 mov eax, esi
// 008d5d60  5e                   pop esi
// 008d5d61  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
