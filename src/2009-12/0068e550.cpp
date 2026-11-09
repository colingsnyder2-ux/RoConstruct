// from server: 100% by auto
// roc 2009-12 0068e550  unit: RBX::VStarterPackService::?$FactoryProduct  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068e550
//
// 0068e550  8bc1                 mov eax, ecx
// 0068e552  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068e556  8b11                 mov edx, dword ptr [ecx]
// 0068e558  8910                 mov dword ptr [eax], edx
// 0068e55a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0068e55d  894804               mov dword ptr [eax + 4], ecx
// 0068e560  85c9                 test ecx, ecx
// 0068e562  740c                 je 0x68e570
// 0068e564  83c104               add ecx, 4
// 0068e567  ba01000000           mov edx, 1
// 0068e56c  f00fc111             lock xadd dword ptr [ecx], edx
// 0068e570  c20800               ret 8
// library boost-1.36.0/libs\regex\src\instances.cpp (function ??$?0V?$w32_regex_traits_implementation@D@re_detail@boost@@@?$shared_ptr@$$CBV?$w32_regex_traits_implementation@D@re_detail@boost@@@boost@@QAE@ABV?$shared_ptr@V?$w32_regex_traits_implementation@D@re_detail@boost@@@1@Usp_empty@detail@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/regex/src/instances.cpp
