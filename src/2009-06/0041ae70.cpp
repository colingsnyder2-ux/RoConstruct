// from server: 100% by auto
// roc 2009-06 0041ae70  unit: rbx::signals::connection::slot  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041ae70
//
// 0041ae70  51                   push ecx
// 0041ae71  8b11                 mov edx, dword ptr [ecx]
// 0041ae73  8b442408             mov eax, dword ptr [esp + 8]
// 0041ae77  8910                 mov dword ptr [eax], edx
// 0041ae79  8b4904               mov ecx, dword ptr [ecx + 4]
// 0041ae7c  c7042400000000       mov dword ptr [esp], 0
// 0041ae83  894804               mov dword ptr [eax + 4], ecx
// 0041ae86  85c9                 test ecx, ecx
// 0041ae88  740c                 je 0x41ae96
// 0041ae8a  83c104               add ecx, 4
// 0041ae8d  ba01000000           mov edx, 1
// 0041ae92  f00fc111             lock xadd dword ptr [ecx], edx
// 0041ae96  59                   pop ecx
// 0041ae97  c20400               ret 4
// library boost-1.40.0/libs\regex\src\instances.cpp (function ?get_named_subs@?$basic_regex@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QBE?AV?$shared_ptr@V?$named_subexpressions@D@re_detail@boost@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
