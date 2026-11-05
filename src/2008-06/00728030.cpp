// from server: 100% by auto
// roc 2008-06 00728030  unit: CXTPRibbonTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00728030
//
// 00728030  56                   push esi
// 00728031  8bf1                 mov esi, ecx
// 00728033  e8283e0700           call 0x79be60
// 00728038  c706fc178600         mov dword ptr [esi], 0x8617fc
// 0072803e  8bc6                 mov eax, esi
// 00728040  5e                   pop esi
// 00728041  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
