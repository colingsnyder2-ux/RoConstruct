// from server: 100% by auto
// roc 2011-06 008e5de0  unit: CXTSplitterWndThemeFactory  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e5de0
//
// 008e5de0  56                   push esi
// 008e5de1  8bf1                 mov esi, ecx
// 008e5de3  e86858f8ff           call 0x86b650
// 008e5de8  c7068c8aad00         mov dword ptr [esi], 0xad8a8c
// 008e5dee  8bc6                 mov eax, esi
// 008e5df0  5e                   pop esi
// 008e5df1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
