// from server: 100% by auto
// roc 2012-06 00a78da0  unit: CXTColorSelectorCtrlTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a78da0
//
// 00a78da0  56                   push esi
// 00a78da1  8bf1                 mov esi, ecx
// 00a78da3  e858ffffff           call 0xa78d00
// 00a78da8  c706a897c200         mov dword ptr [esi], 0xc297a8
// 00a78dae  8bc6                 mov eax, esi
// 00a78db0  5e                   pop esi
// 00a78db1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
