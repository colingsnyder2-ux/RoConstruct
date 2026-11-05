// from server: 100% by auto
// roc 2007-08 007200a0  unit: CXTColorSelectorCtrlThemeOfficeXP  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007200a0
//
// 007200a0  56                   push esi
// 007200a1  8bf1                 mov esi, ecx
// 007200a3  e868ffffff           call 0x720010
// 007200a8  c70624227e00         mov dword ptr [esi], 0x7e2224
// 007200ae  8bc6                 mov eax, esi
// 007200b0  5e                   pop esi
// 007200b1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
