// from server: 100% by auto
// roc 2011-06 008d5870  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d5870
//
// 008d5870  56                   push esi
// 008d5871  8bf1                 mov esi, ecx
// 008d5873  e8583d0000           call 0x8d95d0
// 008d5878  c7069c7aad00         mov dword ptr [esi], 0xad7a9c
// 008d587e  8bc6                 mov eax, esi
// 008d5880  5e                   pop esi
// 008d5881  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
