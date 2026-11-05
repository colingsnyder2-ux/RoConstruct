// from server: 100% by auto
// roc 2009-06 00814550  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814550
//
// 00814550  56                   push esi
// 00814551  8bf1                 mov esi, ecx
// 00814553  e83878f5ff           call 0x76bd90
// 00814558  c706a4d89000         mov dword ptr [esi], 0x90d8a4
// 0081455e  8bc6                 mov eax, esi
// 00814560  5e                   pop esi
// 00814561  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
