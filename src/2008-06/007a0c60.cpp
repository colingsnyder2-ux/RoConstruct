// from server: 100% by auto
// roc 2008-06 007a0c60  unit: CXTColorSelectorCtrlThemeOfficeXP  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a0c60
//
// 007a0c60  56                   push esi
// 007a0c61  8bf1                 mov esi, ecx
// 007a0c63  e868ffffff           call 0x7a0bd0
// 007a0c68  c70604f08600         mov dword ptr [esi], 0x86f004
// 007a0c6e  8bc6                 mov eax, esi
// 007a0c70  5e                   pop esi
// 007a0c71  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
