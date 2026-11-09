// from server: 100% by auto
// roc 2012-06 00a45a50  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a45a50
//
// 00a45a50  56                   push esi
// 00a45a51  8bf1                 mov esi, ecx
// 00a45a53  e86ecff3ff           call 0x9829c6
// 00a45a58  c706a427c200         mov dword ptr [esi], 0xc227a4
// 00a45a5e  8bc6                 mov eax, esi
// 00a45a60  5e                   pop esi
// 00a45a61  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
