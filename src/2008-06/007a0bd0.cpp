// from server: 100% by auto
// roc 2008-06 007a0bd0  unit: CXTColorSelectorCtrlTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a0bd0
//
// 007a0bd0  56                   push esi
// 007a0bd1  8bf1                 mov esi, ecx
// 007a0bd3  e858ffffff           call 0x7a0b30
// 007a0bd8  c706e8ef8600         mov dword ptr [esi], 0x86efe8
// 007a0bde  8bc6                 mov eax, esi
// 007a0be0  5e                   pop esi
// 007a0be1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
