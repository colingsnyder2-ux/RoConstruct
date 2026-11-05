// from server: 100% by auto
// roc 2008-06 0078c290  unit: CXTSplitterWndThemeFactory  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0078c290
//
// 0078c290  56                   push esi
// 0078c291  8bf1                 mov esi, ecx
// 0078c293  e8d813f8ff           call 0x70d670
// 0078c298  c70684a78600         mov dword ptr [esi], 0x86a784
// 0078c29e  8bc6                 mov eax, esi
// 0078c2a0  5e                   pop esi
// 0078c2a1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
