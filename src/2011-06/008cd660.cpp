// from server: 100% by auto
// roc 2011-06 008cd660  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008cd660
//
// 008cd660  56                   push esi
// 008cd661  8bf1                 mov esi, ecx
// 008cd663  e8ded2f3ff           call 0x80a946
// 008cd668  c7060c71ad00         mov dword ptr [esi], 0xad710c
// 008cd66e  8bc6                 mov eax, esi
// 008cd670  5e                   pop esi
// 008cd671  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
