// from server: 100% by auto
// roc 2007-08 004178f0  unit: Marshaller  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004178f0
//
// 004178f0  51                   push ecx
// 004178f1  8b11                 mov edx, dword ptr [ecx]
// 004178f3  8b442408             mov eax, dword ptr [esp + 8]
// 004178f7  8910                 mov dword ptr [eax], edx
// 004178f9  8b4904               mov ecx, dword ptr [ecx + 4]
// 004178fc  85c9                 test ecx, ecx
// 004178fe  c7042400000000       mov dword ptr [esp], 0
// 00417905  894804               mov dword ptr [eax + 4], ecx
// 00417908  740c                 je 0x417916
// 0041790a  83c104               add ecx, 4
// 0041790d  ba01000000           mov edx, 1
// 00417912  f00fc111             lock xadd dword ptr [ecx], edx
// 00417916  59                   pop ecx
// 00417917  c20400               ret 4
// library boost-1.40.0/libs\regex\src\instances.cpp (function ?get_named_subs@?$basic_regex@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QBE?AV?$shared_ptr@V?$named_subexpressions@D@re_detail@boost@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
