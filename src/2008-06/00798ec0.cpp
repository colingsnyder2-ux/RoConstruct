// from server: 100% by auto
// roc 2008-06 00798ec0  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00798ec0
//
// 00798ec0  56                   push esi
// 00798ec1  8bf1                 mov esi, ecx
// 00798ec3  e888a5f5ff           call 0x6f3450
// 00798ec8  c70644c88600         mov dword ptr [esi], 0x86c844
// 00798ece  8bc6                 mov eax, esi
// 00798ed0  5e                   pop esi
// 00798ed1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
