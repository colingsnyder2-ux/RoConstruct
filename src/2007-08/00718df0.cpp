// from server: 100% by auto
// roc 2007-08 00718df0  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00718df0
//
// 00718df0  56                   push esi
// 00718df1  8bf1                 mov esi, ecx
// 00718df3  e89830f6ff           call 0x67be90
// 00718df8  c70624f97d00         mov dword ptr [esi], 0x7df924
// 00718dfe  8bc6                 mov eax, esi
// 00718e00  5e                   pop esi
// 00718e01  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
