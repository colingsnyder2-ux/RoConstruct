// from server: 100% by auto
// roc 2010-06 007476d0  unit: RBX::D6Link  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007476d0
//
// 007476d0  56                   push esi
// 007476d1  8bf1                 mov esi, ecx
// 007476d3  e808900000           call 0x7506e0
// 007476d8  c706fc11a500         mov dword ptr [esi], 0xa511fc
// 007476de  8bc6                 mov eax, esi
// 007476e0  5e                   pop esi
// 007476e1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
