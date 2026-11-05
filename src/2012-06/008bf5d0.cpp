// from server: 100% by auto
// roc 2012-06 008bf5d0  unit: RBX::SpatialFilter  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008bf5d0
//
// 008bf5d0  56                   push esi
// 008bf5d1  8bf1                 mov esi, ecx
// 008bf5d3  e858670400           call 0x905d30
// 008bf5d8  c7065456be00         mov dword ptr [esi], 0xbe5654
// 008bf5de  8bc6                 mov eax, esi
// 008bf5e0  5e                   pop esi
// 008bf5e1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
