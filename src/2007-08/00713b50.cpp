// from server: 100% by auto
// roc 2007-08 00713b50  unit: CXTCaptionTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00713b50
//
// 00713b50  56                   push esi
// 00713b51  8bf1                 mov esi, ecx
// 00713b53  e868ffffff           call 0x713ac0
// 00713b58  c706bcea7d00         mov dword ptr [esi], 0x7deabc
// 00713b5e  8bc6                 mov eax, esi
// 00713b60  5e                   pop esi
// 00713b61  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
