// from server: 100% by auto
// roc 2012-06 0040ba70  unit: boost::exception_detail::clone_base  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ba70
//
// 0040ba70  837c240400           cmp dword ptr [esp + 4], 0
// 0040ba75  7510                 jne 0x40ba87
// 0040ba77  817c240800000080     cmp dword ptr [esp + 8], 0x80000000
// 0040ba7f  7506                 jne 0x40ba87
// 0040ba81  b801000000           mov eax, 1
// 0040ba86  c3                   ret 
// 0040ba87  33c0                 xor eax, eax
// 0040ba89  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_neg_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
