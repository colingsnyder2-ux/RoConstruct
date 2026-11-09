// from server: 100% by auto
// roc 2009-06 007fe420  unit: CXTSplitterWndThemeFactory  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007fe420
//
// 007fe420  56                   push esi
// 007fe421  8bf1                 mov esi, ecx
// 007fe423  e8380af8ff           call 0x77ee60
// 007fe428  c706fca79000         mov dword ptr [esi], 0x90a7fc
// 007fe42e  8bc6                 mov eax, esi
// 007fe430  5e                   pop esi
// 007fe431  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
