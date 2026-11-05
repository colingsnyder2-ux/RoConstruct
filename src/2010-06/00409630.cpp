// from server: 100% by auto
// roc 2010-06 00409630  unit: VAuthoringSettings::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00409630
//
// 00409630  51                   push ecx
// 00409631  8b11                 mov edx, dword ptr [ecx]
// 00409633  8b442408             mov eax, dword ptr [esp + 8]
// 00409637  8910                 mov dword ptr [eax], edx
// 00409639  8b4904               mov ecx, dword ptr [ecx + 4]
// 0040963c  c7042400000000       mov dword ptr [esp], 0
// 00409643  894804               mov dword ptr [eax + 4], ecx
// 00409646  85c9                 test ecx, ecx
// 00409648  740c                 je 0x409656
// 0040964a  83c104               add ecx, 4
// 0040964d  ba01000000           mov edx, 1
// 00409652  f00fc111             lock xadd dword ptr [ecx], edx
// 00409656  59                   pop ecx
// 00409657  c20400               ret 4
// library boost-1.40.0/libs\regex\src\instances.cpp (function ?get_named_subs@?$basic_regex@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QBE?AV?$shared_ptr@V?$named_subexpressions@D@re_detail@boost@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
