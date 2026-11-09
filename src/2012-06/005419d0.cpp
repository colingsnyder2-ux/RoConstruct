// from server: 100% by auto
// roc 2012-06 005419d0  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005419d0
//
// 005419d0  8bc1                 mov eax, ecx
// 005419d2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005419d6  8b11                 mov edx, dword ptr [ecx]
// 005419d8  8910                 mov dword ptr [eax], edx
// 005419da  8b4904               mov ecx, dword ptr [ecx + 4]
// 005419dd  894804               mov dword ptr [eax + 4], ecx
// 005419e0  85c9                 test ecx, ecx
// 005419e2  740c                 je 0x5419f0
// 005419e4  83c104               add ecx, 4
// 005419e7  ba01000000           mov edx, 1
// 005419ec  f00fc111             lock xadd dword ptr [ecx], edx
// 005419f0  c20800               ret 8
// library boost-1.36.0/libs\regex\src\instances.cpp (function ??$?0V?$w32_regex_traits_implementation@D@re_detail@boost@@@?$shared_ptr@$$CBV?$w32_regex_traits_implementation@D@re_detail@boost@@@boost@@QAE@ABV?$shared_ptr@V?$w32_regex_traits_implementation@D@re_detail@boost@@@1@Usp_empty@detail@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/instances.cpp
