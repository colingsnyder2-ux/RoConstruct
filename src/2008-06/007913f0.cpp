// from server: 100% by auto
// roc 2008-06 007913f0  unit: CXTCaptionTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007913f0
//
// 007913f0  56                   push esi
// 007913f1  8bf1                 mov esi, ecx
// 007913f3  e868ffffff           call 0x791360
// 007913f8  c70674af8600         mov dword ptr [esi], 0x86af74
// 007913fe  8bc6                 mov eax, esi
// 00791400  5e                   pop esi
// 00791401  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
