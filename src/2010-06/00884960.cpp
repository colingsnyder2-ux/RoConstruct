// from server: 100% by auto
// roc 2010-06 00884960  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884960
//
// 00884960  56                   push esi
// 00884961  8bf1                 mov esi, ecx
// 00884963  e8283d0000           call 0x888690
// 00884968  c70644eba600         mov dword ptr [esi], 0xa6eb44
// 0088496e  8bc6                 mov eax, esi
// 00884970  5e                   pop esi
// 00884971  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
