// from server: 100% by auto
// roc 2012-06 00a75170  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a75170
//
// 00a75170  56                   push esi
// 00a75171  8bf1                 mov esi, ecx
// 00a75173  e8a8b8f5ff           call 0x9d0a20
// 00a75178  c706bc7ac200         mov dword ptr [esi], 0xc27abc
// 00a7517e  8bc6                 mov eax, esi
// 00a75180  5e                   pop esi
// 00a75181  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
