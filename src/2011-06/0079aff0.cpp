// from server: 100% by auto
// roc 2011-06 0079aff0  unit: RBX::D6Link  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0079aff0
//
// 0079aff0  56                   push esi
// 0079aff1  8bf1                 mov esi, ecx
// 0079aff3  e828690000           call 0x7a1920
// 0079aff8  c706f4c4ab00         mov dword ptr [esi], 0xabc4f4
// 0079affe  8bc6                 mov eax, esi
// 0079b000  5e                   pop esi
// 0079b001  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
