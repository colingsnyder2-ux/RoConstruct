// from server: 100% by auto
// roc 2009-06 006cebf0  unit: RBX::RevoluteLink  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cebf0
//
// 006cebf0  56                   push esi
// 006cebf1  8bf1                 mov esi, ecx
// 006cebf3  e8f8350000           call 0x6d21f0
// 006cebf8  c7069cc88e00         mov dword ptr [esi], 0x8ec89c
// 006cebfe  8bc6                 mov eax, esi
// 006cec00  5e                   pop esi
// 006cec01  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
