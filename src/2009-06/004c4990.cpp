// from server: 100% by auto
// roc 2009-06 004c4990  unit: RBX::Network::Players::Plugin  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c4990
//
// 004c4990  8bc1                 mov eax, ecx
// 004c4992  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c4996  8b11                 mov edx, dword ptr [ecx]
// 004c4998  8910                 mov dword ptr [eax], edx
// 004c499a  8b4904               mov ecx, dword ptr [ecx + 4]
// 004c499d  894804               mov dword ptr [eax + 4], ecx
// 004c49a0  85c9                 test ecx, ecx
// 004c49a2  740c                 je 0x4c49b0
// 004c49a4  83c104               add ecx, 4
// 004c49a7  ba01000000           mov edx, 1
// 004c49ac  f00fc111             lock xadd dword ptr [ecx], edx
// 004c49b0  c20800               ret 8
// library boost-1.36.0/libs\regex\src\instances.cpp (function ??$?0V?$w32_regex_traits_implementation@D@re_detail@boost@@@?$shared_ptr@$$CBV?$w32_regex_traits_implementation@D@re_detail@boost@@@boost@@QAE@ABV?$shared_ptr@V?$w32_regex_traits_implementation@D@re_detail@boost@@@1@Usp_empty@detail@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/instances.cpp
