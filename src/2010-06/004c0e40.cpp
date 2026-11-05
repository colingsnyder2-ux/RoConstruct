// from server: 100% by auto
// roc 2010-06 004c0e40  unit: RBX::Network::Players  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c0e40
//
// 004c0e40  8bc1                 mov eax, ecx
// 004c0e42  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c0e46  8b11                 mov edx, dword ptr [ecx]
// 004c0e48  8910                 mov dword ptr [eax], edx
// 004c0e4a  8b4904               mov ecx, dword ptr [ecx + 4]
// 004c0e4d  894804               mov dword ptr [eax + 4], ecx
// 004c0e50  85c9                 test ecx, ecx
// 004c0e52  740c                 je 0x4c0e60
// 004c0e54  83c104               add ecx, 4
// 004c0e57  ba01000000           mov edx, 1
// 004c0e5c  f00fc111             lock xadd dword ptr [ecx], edx
// 004c0e60  c20800               ret 8
// library boost-1.36.0/libs\regex\src\instances.cpp (function ??$?0V?$w32_regex_traits_implementation@D@re_detail@boost@@@?$shared_ptr@$$CBV?$w32_regex_traits_implementation@D@re_detail@boost@@@boost@@QAE@ABV?$shared_ptr@V?$w32_regex_traits_implementation@D@re_detail@boost@@@1@Usp_empty@detail@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/instances.cpp
