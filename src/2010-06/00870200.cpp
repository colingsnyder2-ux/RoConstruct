// from server: 100% by auto
// roc 2010-06 00870200  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00870200
//
// 00870200  56                   push esi
// 00870201  8bf1                 mov esi, ecx
// 00870203  e88080f3ff           call 0x7a8288
// 00870208  c706fcc6a600         mov dword ptr [esi], 0xa6c6fc
// 0087020e  8bc6                 mov eax, esi
// 00870210  5e                   pop esi
// 00870211  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
