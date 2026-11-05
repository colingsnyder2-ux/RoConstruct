// from server: 100% by auto
// roc 2012-06 004289e0  unit: rbx::signals::connection::islot  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004289e0
//
// 004289e0  51                   push ecx
// 004289e1  8b11                 mov edx, dword ptr [ecx]
// 004289e3  8b442408             mov eax, dword ptr [esp + 8]
// 004289e7  8910                 mov dword ptr [eax], edx
// 004289e9  8b4904               mov ecx, dword ptr [ecx + 4]
// 004289ec  c7042400000000       mov dword ptr [esp], 0
// 004289f3  894804               mov dword ptr [eax + 4], ecx
// 004289f6  85c9                 test ecx, ecx
// 004289f8  740c                 je 0x428a06
// 004289fa  83c104               add ecx, 4
// 004289fd  ba01000000           mov edx, 1
// 00428a02  f00fc111             lock xadd dword ptr [ecx], edx
// 00428a06  59                   pop ecx
// 00428a07  c20400               ret 4
// library boost-1.40.0/libs\regex\src\instances.cpp (function ?get_named_subs@?$basic_regex@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QBE?AV?$shared_ptr@V?$named_subexpressions@D@re_detail@boost@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
