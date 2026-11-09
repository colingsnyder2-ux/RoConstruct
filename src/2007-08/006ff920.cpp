// from server: 100% by auto
// roc 2007-08 006ff920  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ff920
//
// 006ff920  56                   push esi
// 006ff921  8bf1                 mov esi, ecx
// 006ff923  e8783f0000           call 0x7038a0
// 006ff928  c70664cf7d00         mov dword ptr [esi], 0x7dcf64
// 006ff92e  8bc6                 mov eax, esi
// 006ff930  5e                   pop esi
// 006ff931  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
