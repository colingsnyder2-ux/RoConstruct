// from server: 100% by auto
// roc 2010-06 008a74b0  unit: CXTColorSelectorCtrlTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a74b0
//
// 008a74b0  56                   push esi
// 008a74b1  8bf1                 mov esi, ecx
// 008a74b3  e858ffffff           call 0x8a7410
// 008a74b8  c706903ca700         mov dword ptr [esi], 0xa73c90
// 008a74be  8bc6                 mov eax, esi
// 008a74c0  5e                   pop esi
// 008a74c1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
