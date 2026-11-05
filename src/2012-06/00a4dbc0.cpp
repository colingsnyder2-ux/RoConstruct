// from server: 100% by auto
// roc 2012-06 00a4dbc0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4dbc0
//
// 00a4dbc0  56                   push esi
// 00a4dbc1  8bf1                 mov esi, ecx
// 00a4dbc3  e8183d0000           call 0xa518e0
// 00a4dbc8  c7063431c200         mov dword ptr [esi], 0xc23134
// 00a4dbce  8bc6                 mov eax, esi
// 00a4dbd0  5e                   pop esi
// 00a4dbd1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
