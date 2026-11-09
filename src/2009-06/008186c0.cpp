// from server: 100% by auto
// roc 2009-06 008186c0  unit: CXTColorSelectorCtrlTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008186c0
//
// 008186c0  56                   push esi
// 008186c1  8bf1                 mov esi, ecx
// 008186c3  e858ffffff           call 0x818620
// 008186c8  c70628f59000         mov dword ptr [esi], 0x90f528
// 008186ce  8bc6                 mov eax, esi
// 008186d0  5e                   pop esi
// 008186d1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
