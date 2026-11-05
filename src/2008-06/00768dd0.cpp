// from server: 100% by auto
// roc 2008-06 00768dd0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00768dd0
//
// 00768dd0  56                   push esi
// 00768dd1  8bf1                 mov esi, ecx
// 00768dd3  e8b880f3ff           call 0x6a0e90
// 00768dd8  c7066c6f8600         mov dword ptr [esi], 0x866f6c
// 00768dde  8bc6                 mov eax, esi
// 00768de0  5e                   pop esi
// 00768de1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
