// from server: 100% by auto
// roc 2009-12 004ffeb0  unit: RBX::Reflection::VDescribedBase::V?$shared_ptr::?$holder  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ffeb0
//
// 004ffeb0  51                   push ecx
// 004ffeb1  8b11                 mov edx, dword ptr [ecx]
// 004ffeb3  8b442408             mov eax, dword ptr [esp + 8]
// 004ffeb7  8910                 mov dword ptr [eax], edx
// 004ffeb9  8b4904               mov ecx, dword ptr [ecx + 4]
// 004ffebc  c7042400000000       mov dword ptr [esp], 0
// 004ffec3  894804               mov dword ptr [eax + 4], ecx
// 004ffec6  85c9                 test ecx, ecx
// 004ffec8  740c                 je 0x4ffed6
// 004ffeca  83c104               add ecx, 4
// 004ffecd  ba01000000           mov edx, 1
// 004ffed2  f00fc111             lock xadd dword ptr [ecx], edx
// 004ffed6  59                   pop ecx
// 004ffed7  c20400               ret 4
// library boost-1.40.0/libs\regex\src\instances.cpp (function ?get_named_subs@?$basic_regex@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QBE?AV?$shared_ptr@V?$named_subexpressions@D@re_detail@boost@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
