// from server: 100% by auto
// roc 2011-06 00499170  unit: VerbBinderJob  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00499170
//
// 00499170  51                   push ecx
// 00499171  8b11                 mov edx, dword ptr [ecx]
// 00499173  8b442408             mov eax, dword ptr [esp + 8]
// 00499177  8910                 mov dword ptr [eax], edx
// 00499179  8b4904               mov ecx, dword ptr [ecx + 4]
// 0049917c  c7042400000000       mov dword ptr [esp], 0
// 00499183  894804               mov dword ptr [eax + 4], ecx
// 00499186  85c9                 test ecx, ecx
// 00499188  740c                 je 0x499196
// 0049918a  83c104               add ecx, 4
// 0049918d  ba01000000           mov edx, 1
// 00499192  f00fc111             lock xadd dword ptr [ecx], edx
// 00499196  59                   pop ecx
// 00499197  c20400               ret 4
// library boost-1.40.0/libs\regex\src\instances.cpp (function ?get_named_subs@?$basic_regex@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@boost@@QBE?AV?$shared_ptr@V?$named_subexpressions@D@re_detail@boost@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
