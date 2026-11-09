// from server: 100% by auto
// roc 2012-06 00a4e080  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4e080
//
// 00a4e080  56                   push esi
// 00a4e081  8bf1                 mov esi, ecx
// 00a4e083  e8e84bfbff           call 0xa02c70
// 00a4e088  c706a433c200         mov dword ptr [esi], 0xc233a4
// 00a4e08e  8bc6                 mov eax, esi
// 00a4e090  5e                   pop esi
// 00a4e091  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
