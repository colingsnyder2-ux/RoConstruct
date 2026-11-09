// from server: 100% by auto
// roc 2010-06 0088d170  unit: CXTSplitterWndThemeFactory  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088d170
//
// 0088d170  56                   push esi
// 0088d171  8bf1                 mov esi, ecx
// 0088d173  e8180df8ff           call 0x80de90
// 0088d178  c70664efa600         mov dword ptr [esi], 0xa6ef64
// 0088d17e  8bc6                 mov eax, esi
// 0088d180  5e                   pop esi
// 0088d181  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
