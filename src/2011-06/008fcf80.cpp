// from server: 100% by auto
// roc 2011-06 008fcf80  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008fcf80
//
// 008fcf80  56                   push esi
// 008fcf81  8bf1                 mov esi, ecx
// 008fcf83  e878b6f5ff           call 0x858600
// 008fcf88  c706b4c4ad00         mov dword ptr [esi], 0xadc4b4
// 008fcf8e  8bc6                 mov eax, esi
// 008fcf90  5e                   pop esi
// 008fcf91  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
