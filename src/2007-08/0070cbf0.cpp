// from server: 100% by auto
// roc 2007-08 0070cbf0  unit: CXTColorBase  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070cbf0
//
// 0070cbf0  56                   push esi
// 0070cbf1  8bf1                 mov esi, ecx
// 0070cbf3  e898fcffff           call 0x70c890
// 0070cbf8  c70604dc7d00         mov dword ptr [esi], 0x7ddc04
// 0070cbfe  8bc6                 mov eax, esi
// 0070cc00  5e                   pop esi
// 0070cc01  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
