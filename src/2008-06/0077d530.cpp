// from server: 100% by auto
// roc 2008-06 0077d530  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0077d530
//
// 0077d530  56                   push esi
// 0077d531  8bf1                 mov esi, ecx
// 0077d533  e8483d0000           call 0x781280
// 0077d538  c706b4938600         mov dword ptr [esi], 0x8693b4
// 0077d53e  8bc6                 mov eax, esi
// 0077d540  5e                   pop esi
// 0077d541  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
