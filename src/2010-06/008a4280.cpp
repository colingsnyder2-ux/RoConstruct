// from server: 100% by auto
// roc 2010-06 008a4280  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a4280
//
// 008a4280  56                   push esi
// 008a4281  8bf1                 mov esi, ecx
// 008a4283  e88869f5ff           call 0x7fac10
// 008a4288  c7060429a700         mov dword ptr [esi], 0xa72904
// 008a428e  8bc6                 mov eax, esi
// 008a4290  5e                   pop esi
// 008a4291  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
