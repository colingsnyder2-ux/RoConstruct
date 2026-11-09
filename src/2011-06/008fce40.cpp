// from server: 100% by auto
// roc 2011-06 008fce40  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008fce40
//
// 008fce40  56                   push esi
// 008fce41  8bf1                 mov esi, ecx
// 008fce43  e8b8b7f5ff           call 0x858600
// 008fce48  c70634c4ad00         mov dword ptr [esi], 0xadc434
// 008fce4e  8bc6                 mov eax, esi
// 008fce50  5e                   pop esi
// 008fce51  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
