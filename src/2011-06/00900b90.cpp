// from server: 100% by auto
// roc 2011-06 00900b90  unit: CXTColorSelectorCtrlTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00900b90
//
// 00900b90  56                   push esi
// 00900b91  8bf1                 mov esi, ecx
// 00900b93  e858ffffff           call 0x900af0
// 00900b98  c706e8e0ad00         mov dword ptr [esi], 0xade0e8
// 00900b9e  8bc6                 mov eax, esi
// 00900ba0  5e                   pop esi
// 00900ba1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
