// from server: 100% by auto
// roc 2009-06 007e15c0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e15c0
//
// 007e15c0  56                   push esi
// 007e15c1  8bf1                 mov esi, ecx
// 007e15c3  e8587df3ff           call 0x719320
// 007e15c8  c706a47f9000         mov dword ptr [esi], 0x907fa4
// 007e15ce  8bc6                 mov eax, esi
// 007e15d0  5e                   pop esi
// 007e15d1  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
