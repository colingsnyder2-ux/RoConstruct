// from server: 100% by auto
// roc 2009-06 00818750  unit: CXTColorSelectorCtrlThemeOfficeXP  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00818750
//
// 00818750  56                   push esi
// 00818751  8bf1                 mov esi, ecx
// 00818753  e868ffffff           call 0x8186c0
// 00818758  c70644f59000         mov dword ptr [esi], 0x90f544
// 0081875e  8bc6                 mov eax, esi
// 00818760  5e                   pop esi
// 00818761  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
