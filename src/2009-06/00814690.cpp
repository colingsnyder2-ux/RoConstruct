// from server: 100% by auto
// roc 2009-06 00814690  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814690
//
// 00814690  56                   push esi
// 00814691  8bf1                 mov esi, ecx
// 00814693  e8f876f5ff           call 0x76bd90
// 00814698  c70624d99000         mov dword ptr [esi], 0x90d924
// 0081469e  8bc6                 mov eax, esi
// 008146a0  5e                   pop esi
// 008146a1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
