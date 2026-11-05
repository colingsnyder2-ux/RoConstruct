// from server: 100% by auto
// roc 2009-06 007f5bd0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5bd0
//
// 007f5bd0  56                   push esi
// 007f5bd1  8bf1                 mov esi, ecx
// 007f5bd3  e8683d0000           call 0x7f9940
// 007f5bd8  c706dca39000         mov dword ptr [esi], 0x90a3dc
// 007f5bde  8bc6                 mov eax, esi
// 007f5be0  5e                   pop esi
// 007f5be1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
