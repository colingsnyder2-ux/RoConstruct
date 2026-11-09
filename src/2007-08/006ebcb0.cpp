// from server: 100% by auto
// roc 2007-08 006ebcb0  unit: CXTPDockingPanePaintManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ebcb0
//
// 006ebcb0  56                   push esi
// 006ebcb1  8bf1                 mov esi, ecx
// 006ebcb3  e82249f4ff           call 0x6305da
// 006ebcb8  c7068cac7d00         mov dword ptr [esi], 0x7dac8c
// 006ebcbe  8bc6                 mov eax, esi
// 006ebcc0  5e                   pop esi
// 006ebcc1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
