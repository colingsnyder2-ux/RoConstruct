// from server: 100% by auto
// roc 2009-06 007f60c0  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f60c0
//
// 007f60c0  56                   push esi
// 007f60c1  8bf1                 mov esi, ecx
// 007f60c3  e868fcf9ff           call 0x795d30
// 007f60c8  c7064ca69000         mov dword ptr [esi], 0x90a64c
// 007f60ce  8bc6                 mov eax, esi
// 007f60d0  5e                   pop esi
// 007f60d1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
